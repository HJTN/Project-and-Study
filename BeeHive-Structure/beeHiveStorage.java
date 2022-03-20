public class beeHiveStorage {
    private final String thisStorageName;
    private int typeNum;
    private String strItem;
    private Integer intItem;

    // Constructor...
    beeHiveStorage(String name, int typenum) {
        this.thisStorageName = name;
        this.typeNum = typenum;
    }

    // Methods...
    // StorageName Relate...
    String getStorageName() {
        return thisStorageName;
    }

    // Type Num Relate...
    int getTypeNum() {
        return typeNum;
    }

    void setTypeNum(int typenum) {
        this.typeNum = typenum;
    }

    // Item Relate...
    void setItem(String item) {
        switch (typeNum) {
            case 0:
                this.strItem = item;
                break;
            
            case 1:
                this.intItem = Integer.parseInt(item);
                break;
        }
        this.strItem = item;
    }

    String getstrItem() {
        return strItem;
    }

    Integer getintItem() {
        return intItem;
    }

    void printItem() {
        System.out.println("[" + thisStorageName + "]");
        switch (typeNum) {
            case 0:
                System.out.println(strItem);
                break;
            
            case 1:
                System.out.println(intItem);
                break;
        }
    }
}