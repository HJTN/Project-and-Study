import java.util.ArrayList;
import java.util.TreeMap;

public class storageManager {
    private final String storageName;
    private TreeMap<String, ArrayList<beeHiveStorage>> parentSto;
    private int childStoSize;

    // Constructor...
    storageManager(String storageName) {
        this.storageName = storageName;
        this.parentSto = new TreeMap<String, ArrayList<beeHiveStorage>>();
        this.childStoSize = 0;
        setparentSto();
    }

    // Method...
    // StoMap Relate...
    void setparentSto() {
        this.parentSto.put(storageName, new ArrayList<>());
    }

    ArrayList<beeHiveStorage> getParentSto() {
        return this.parentSto.get(storageName);
    }

    void addChildStorage(beeHiveStorage childSto) {
        getParentSto().add(childSto);
        this.childStoSize = getParentSto().size();
    }

    void removeChildStorage(beeHiveStorage childSto) {
        getParentSto().remove(childSto);
    }

    int getChildStoSize() {
        return childStoSize;
    }

}
