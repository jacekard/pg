import java.util.Comparator;

class MyComparator implements Comparator<DiskElement> {

        public int compare(DiskElement a, DiskElement b) {
            if (a.file.getName().compareTo(b.file.getName()) > 0)
                return -1;
            else if (a.file.getName().compareTo(b.file.getName()) < 0)
                return 1;
            else
                return 0;
        }
}

