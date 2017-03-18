package javaapplication1;

public class Punkt {

    /*
 * Słowo kluczowe final oznacza, że po pierwszym przypisaniu
 * zawartość pól x oraz y nie może zostać zmieniona
 * w tym miejscu jest to odpowiednik słowa kluczowego const
 * z języka C++.
     */
    private final double x, y;

    public Punkt(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double getX() {
        return this.x;
    }

    public double getY() {
        return this.y;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Punkt) {
            Punkt inny = (Punkt) obj;
            if (this.x == inny.x & this.y == inny.y) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int hashCode() {
        return -59 * (Double.hashCode(x) + Double.hashCode(y)) + 11;
    }

    @Override
    public String toString() {
        return "Instancja klasy Punkt zawierająca wspolrzedne (" + x + "," + y + ")";
    }
    /**
     * Początek układu współrzędnych. W tym miejscu słowo kluczowe final
     * oznacza, że statyczne pole klasy Punkt nie może zostać zmienione. Dotyczy
     * to jednak samej referencji, a nie obiektu, na który wskazuje.
     */
    public static final Punkt O = new Punkt(0, 0);
    /**
     * Punkt (1,0) w układzie współrzędnych
     */
    public static final Punkt E_X = new Punkt(1, 0);

    /**
     * Punkt (0,1) w układzie współrzędnych
     */
    public static final Punkt E_Y = new Punkt(0, 1);
}
