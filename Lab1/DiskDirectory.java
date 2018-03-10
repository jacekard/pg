import java.io.File;
import java.util.Set;
import java.util.TreeSet;

//DiskDirectory.java
public class DiskDirectory extends DiskElement {
    public Set<DiskElement> children;

    public DiskDirectory(File file, int depth, char symbol, String sortOpt) {
        super(file, depth, symbol);
        if(sortOpt == null)
            children = new TreeSet<>();
        else
            children = new TreeSet<>(new MyComparator());

        File[] files = file.listFiles();

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
        for(DiskElement el : children) {
            el.print();
        }
    }

}
