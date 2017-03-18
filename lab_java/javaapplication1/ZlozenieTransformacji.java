package javaapplication1;

public class ZlozenieTransformacji implements Transformacja {

    private final Transformacja[] tab;

    public ZlozenieTransformacji(Transformacja[] tab) {
        this.tab = tab;
    }

    @Override
    public Transformacja getTranformacjaOdwrotna() throws
            BrakTransformacjiOdwrotnejException {
        if (tab.length == 0) {
            throw new BrakTransformacjiOdwrotnejException("Brak Transformacji");
        }
        return new ZlozenieTransformacji(0);
    }

    @Override
    public Punkt transformuj(Punkt p) {
        for (int i = 0; i < tab.length; i++) {
            return  tab[i].transformacja(new Punkt);
        }
    }
}
