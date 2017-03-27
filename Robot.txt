package bieg.po.lesie;

import java.io.PrintStream;
import java.util.Random;

/**
 *
 * @author TB
 */
public abstract class Robot implements Uczestnik {

    private final String model;
    private final int numerSeryjny;
    protected final Random czynnikiLosowe = new Random();

    private PrintStream mediumKomunikacyjne;

    @Override
    public boolean rozwiazZadanie(Zadanie zadanie) {
        Random generator = new Random();
        int chance = generator.nextInt(99);
        if (chance < 5) {
            return true;
        } else {
            return false;
        }
    }

    public Robot(String model, int numerSeryjny) {
        this.model = model;
        this.numerSeryjny = numerSeryjny;
    }

    @Override
    public void mowDo(PrintStream ps) {
        mediumKomunikacyjne = ps;
    }

    public final String identyfikuj() {
        return model + " nr " + numerSeryjny;
    }

    protected void komunikuj(String komunikat) {
        mediumKomunikacyjne.print(identyfikuj() + " komunikuje: ");
        mediumKomunikacyjne.println(komunikat);
    }

    @Override
    public String toString() {
        return identyfikuj();
    }

}
