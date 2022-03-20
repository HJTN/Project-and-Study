public class inputCommendsCheck {
    private String commend;
    private String[] commends;
    private int totalSize;

    // Constructor...
    inputCommendsCheck(String commend) {
        setCommend(commend);
        setCommends();
        setTotalSize();
    }

    // Method...
    // Commend Relate...
    void setCommend(String commend) {
        this.commend = commend;
    }
    String getCommend() {
        return commend;
    }
    String getCommend(int index) {
        return commends[index];
    }
    
    // 특수 문자 체크...
    boolean checkUniqueCommend() {
        return commend.contains("/");
    }

    // Commends Relate...
    void setCommends() {
        if (checkUniqueCommend()) {
            this.commends = commend.split("/");
            this.commend = commends[0];
        } else {
            this.commends = null;
        }
    }
    String[] getCommends() {
        return commends;
    }
    void printAllCommends() {
        if (commends == null) {
            System.out.println("No Commends");
        } else
            for (String cmd : commends)
                System.out.println(cmd);
    }

    // TotalSize Relate...
    void setTotalSize() {
        this.totalSize = 1;
        if (commends != null) {
            this.totalSize = commends.length;
        }
    }
    int getTotalSize() {
        return totalSize;
    }
}
