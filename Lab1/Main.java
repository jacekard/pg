import java.io.File;
public class Main {
    public static void main(String args[]) {
        String path = "", opt = "";
        for (String arg : args) {
             path += arg + " ";
        }
        opt = path.substring(path.length()-3, path.length()-1);
        path = path.substring(0,path.length()-4);
        File file = new File(path);
        if(file.isDirectory() == false)
            return;
        DiskElement rootDirectory = new DiskDirectory(file, 1, 'K', opt);
        rootDirectory.print();
    }

}
