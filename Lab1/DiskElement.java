import java.io.File;
import java.text.SimpleDateFormat;
import java.util.Date;

//DiskElement.java
public abstract class DiskElement implements Comparable {
    protected File file; //java.io.File;
    protected Date lastModified;
    protected String formattedDate;
    protected char symbol;
    protected int depth;

    public DiskElement(File file, int depth, char symbol) {
        this.file = file;
        this.depth = depth;
        this.symbol = symbol;

        long lastModifiedMS = file.lastModified();
        lastModified = new Date(lastModifiedMS);
        SimpleDateFormat template = new SimpleDateFormat("yyyy-MM-dd");
        formattedDate = template.format(lastModified);
    }

    public void print() {
        if(file == null) return;
        String s = "";
        for(int i = 0; i < depth; i++)
            s += "-";
        System.out.printf("%-55s %s %-10s %n", s+file.getName(), symbol, formattedDate);
    }

    @Override
    public boolean equals(Object o) {

        if (o == this) return true;
        if (!(o instanceof DiskElement)) {
            return false;
        }

        return file.equals(((DiskElement)o).file);
    }


    @Override
    public int hashCode() {
        return file.hashCode();
    }


    @Override
    public int compareTo(Object o) {
        if (!(o instanceof DiskElement))
            return -1;
        DiskElement temp = (DiskElement) o;
        int r = this.file.getName().compareToIgnoreCase(temp.file.getName());
        if (r == 0)
            r = this.lastModified.compareTo(temp.lastModified);

        return r;
    }
}