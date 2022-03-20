public class StorageTypeCheck {
    private String StoType;
    private int typeNum;

    // Constructor...
    StorageTypeCheck(String stotype) {
        setStoType(stotype);
        setTypeNum();
    }

    // Method...
    // StoType Relate...
    void setStoType(String type) {
        this.StoType = type;
    }

    String getStoType() {
        return this.StoType;
    }

    // TypeNum Relate...
    void setTypeNum() {
        switch (StoType) {
            case "String":
                this.typeNum = 0;
                break;

            case "Integer":
                this.typeNum = 1;
                break;
        }
    }
    
    int getTypeNum() {
        return this.typeNum;
    }
}
