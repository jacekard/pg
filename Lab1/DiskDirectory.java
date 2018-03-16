import java.io.File;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

//DiskDirectory.java
public class DiskDirectory extends DiskElement {
    public Set<DiskElement> children;

    public DiskDirectory(File file, int depth, char symbol, String sortOpt) {
        super(file, depth, symbol);
        File[] files = file.listFiles();
        if(files == null || files.length == 0)
            return;
        if(sortOpt.equals("-a")) {
            children = new TreeSet<>();
        }
        else if (sortOpt.equals("-b")) {
            children = new TreeSet<>(new MyComparator());
        }
        else if (sortOpt.equals("-c")) {
            children = new HashSet<>(files.length);
        }


        for(File f : files) {
            if(f.isDirectory()) {
                children.add(new DiskDirectory(f, depth+1, 'K', sortOpt));
            } else if (f.isFile()) {
                children.add(new DiskFile(f, depth+1, 'P'));
            }
        }

    };


    public void print() {
        super.print();
        if(children == null || children.size() == 0)
            return;
        for(DiskElement el : children) {
            el.print();
        }
    }

}