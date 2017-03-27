package bieg.po.lesie;

public class BrakElementu extends Exception {

    public BrakElementu() {
        //Niejawne wywołanie konstruktora klasy nadrzędnej
        //super();
    }

    /*
 * Konstruktor przyjmujący jako parametr tekst opisujący błąd
     */
    public BrakElementu(String message) {
        super(message);
    }

    /*
 * Konstruktor przyjmujący jako parametr referencje do innego
 * wyjątku, który spowodował błąd
     */
    public BrakElementu(Throwable cause) {
        super(cause);
    }

 /*
 * Konstruktor przyjmujący jako parametr tekst opisujący błąd
 * oraz wyjątek, który spowodował błąd.
 */
 public BrakElementu(String message,
            Throwable cause) {
        super(message, cause);
    }
}
