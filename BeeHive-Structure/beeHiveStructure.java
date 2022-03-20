import java.util.Scanner;

// Run Code Files...
public class beeHiveStructure {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        beeHiveStorage current = null;
        while (true) {
            inputCommendsCheck cmd = new inputCommendsCheck(sc.next());

            if (cmd.getCommend().equals("quit"))
                break;

            switch (cmd.getCommend()) {
                case "help":    // Seek Commends
                    System.out.println("Current Commends :"
                            + "\n\t" + "mksto" + "\t: Make a Storage"
                            + "\n\t" + "add" + "\t: if Storage exist, store item"
                            + "\n\t" + "print"  + "\t: print stored items in Storage"
                            + "\n\t" + "quit" + "\t: want to quit this Structure");
                    break;

                case "mksto": // "mkSto/{Storage Type}/{Storage Name}"
                    if (cmd.getTotalSize() == 3) {
                        current = new beeHiveStorage(cmd.getCommend(2),
                                new StorageTypeCheck(cmd.getCommend(1)).getTypeNum());
                    } else {
                        System.out.println("mksto Form is mksto/{Storage Type}/{Storage Name}.");
                    }
                    break;

                case "add": // "add/{Item}"
                    if (current == null) {
                        System.out.println("No Storage now." + "\n"
                                + "First, make a Storage (mksto/{Storage Type}/{Storage Name}).");
                        break;
                    }
                    
                    if (cmd.getTotalSize() == 2) {
                        current.setItem(cmd.getCommend(1));
                    } else {
                        System.out.println("Add Form is add/{Item}.");
                    }
                    break;

                case "print":
                    if (current == null) {
                        System.out.println("No Storage now." + "\n"
                                + "First, make a Storage (mksto/{Storage Type}/{Storage Name}).");
                        break;
                    }
                    
                    current.printItem();
                    break;
                default:
                    System.out.println("The commend you entered is incorrect.\n enter commend again.");
                    break;
            }
        }
        sc.close();
    }
}