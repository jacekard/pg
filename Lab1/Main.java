import java.io.File;
public class Main {
    public static void main(String args[]) {
        String path = args[0], opt = args[1];
        File file = new File(path);
        if(!file.isDirectory())
            return;
        DiskElement rootDirectory = new DiskDirectory(file, 1, 'K', opt);
        rootDirectory.print();
    }

}
