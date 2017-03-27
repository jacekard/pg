package bieg.po.lesie;

import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *
 * @author TB
 */
public class Javalab2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Set<Uczestnik> uczestnicy = new HashSet<>();
        uczestnicy.add(new BagiennyBiegacz("Krzysztof", "Kowalski", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new LesnyBiegacz("Grzegorz", "Choinski", Czlowiek.Plec.MEZCZYZNA));
        uczestnicy.add(new Terminator(1));

        Scanner scanner = new Scanner(System.in);

        System.out.println("Witaj w aplikacji Bieg po Lesie. Wybierz bieg: ");
        System.out.println("1. Górki");
        System.out.println("2. Na przełaj z Matematyką");
        System.out.println("3. Bagienny miks naukowy");
        System.out.println("4. Stworz wlasny bieg");
        int wybor = scanner.nextInt();
        BiegPoLesie bieg;

        switch (wybor) {
            default:
                System.out.println("Niezany wybór. Wybieranie opcji nr 1.");
            case 1:
                bieg = gorki(System.out, System.out);
                break;
            case 2:
                bieg = naPrzelajZMatematyka(System.out, System.out);
                break;
            case 3:
                bieg = bagiennyMiks(System.out, System.out);
                break;
            case 4:
                bieg = wlasny(System.out, System.out);
                break;
        }

        for (Uczestnik u : uczestnicy) {
            bieg.dodajUczestnika(u);
        }

        bieg.przeprowadzImpreze();
    }

    private static BiegPoLesie wlasny(PrintStream mikrofon, PrintStream przestrzenWLesie) {
        BiegPoLesie wlasny_ = new BiegPoLesie("Własny", mikrofon, przestrzenWLesie);
        Scanner scanner = new Scanner(System.in);

        boolean q = true;
        while (q) {
            String opcja;
            try {
                opcja = scanner.next();
                wlasny_.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(opcja));
            } catch (BrakElementu ex) {
                q = false;
                ex.getMessage();
            }
        }
        return wlasny_;
    }

    private static BiegPoLesie gorki(PrintStream mikrofon, PrintStream przestrzenWLesie) {
        BiegPoLesie gorki_ = new BiegPoLesie("Górki", mikrofon, przestrzenWLesie);
        gorki_.dodajElementTrasy(new Zadanie(DziedzinaZadania.MATEMATYKA));
        gorki_.dodajElementTrasy(new Teren(RodzajTerenu.DROGA));
        gorki_.dodajElementTrasy(new Teren(RodzajTerenu.SCIEZKA));
        gorki_.dodajElementTrasy(new Teren(RodzajTerenu.SCIEZKA));
        gorki_.dodajElementTrasy(new Teren(RodzajTerenu.NISKI_LAS));
        gorki_.dodajElementTrasy(new Teren(RodzajTerenu.BAGNO));
        gorki_.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.FIZYKA));
        gorki_.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.MATEMATYKA));
        gorki_.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.NAUKI_LEŚNE));
        gorki_.dodajElementTrasy(new Teren(RodzajTerenu.WYSOKI_LAS));

        return gorki_;

    }

    private static BiegPoLesie naPrzelajZMatematyka(PrintStream mikrofon, PrintStream przestrzenWLesie) {
        BiegPoLesie naPrzelaj = new BiegPoLesie("Na przełaj z matematyką", mikrofon, przestrzenWLesie);

        naPrzelaj.dodajElementTrasy(new Teren(RodzajTerenu.DROGA));
        naPrzelaj.dodajElementTrasy(new Teren(RodzajTerenu.SCIEZKA));
        naPrzelaj.dodajElementTrasy(new Teren(RodzajTerenu.NISKI_LAS));
        naPrzelaj.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.MATEMATYKA));
        naPrzelaj.dodajElementTrasy(new Teren(RodzajTerenu.NISKI_LAS));
        naPrzelaj.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.MATEMATYKA));
        naPrzelaj.dodajElementTrasy(new Teren(RodzajTerenu.NISKI_LAS));
        naPrzelaj.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.MATEMATYKA));
        naPrzelaj.dodajElementTrasy(new Teren(RodzajTerenu.WYSOKI_LAS));

        return naPrzelaj;
    }

    private static BiegPoLesie bagiennyMiks(PrintStream mikrofon, PrintStream przestrzenWLesie) {
        BiegPoLesie miks = new BiegPoLesie("Bagienny miks naukowy", mikrofon, przestrzenWLesie);

        miks.dodajElementTrasy(new Teren(RodzajTerenu.DROGA));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.SCIEZKA));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.BAGNO));
        miks.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.MATEMATYKA));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.BAGNO));
        miks.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.FIZYKA));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.BAGNO));
        miks.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.INFORMATYKA));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.BAGNO));
        miks.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.SZTUKA));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.BAGNO));
        miks.dodajElementTrasy(FabrykaElementowTrasy.utworzElementTrasy(DziedzinaZadania.NAUKI_LEŚNE));
        miks.dodajElementTrasy(new Teren(RodzajTerenu.WYSOKI_LAS));

        return miks;
    }

}
