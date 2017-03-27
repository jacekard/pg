package bieg.po.lesie;

public class FabrykaElementowTrasy {

    Teren Stworz(RodzajTerenu teren) {
        Teren t = new Teren(teren);
        return t;
    }

    Zadanie Stworz(DziedzinaZadania zad) {
        Zadanie z = new Zadanie(zad);
        return z;
    }

    Zadanie Stworz(String napis) {
        Zadanie z;
        Teren t;
        switch (napis) {
            case "MATEMATYKA":
                z = new Zadanie(DziedzinaZadania.valueOf(napis));
                break;
            case "INFORMATYKA":
                z = new Zadanie(DziedzinaZadania.valueOf(napis));
                break;
            case "FIZYKA":
                z = new Zadanie(DziedzinaZadania.valueOf(napis));
                break;
            case "SZTUKA":
                z = new Zadanie(DziedzinaZadania.valueOf(napis));
                break;
            case "NAUKI_LEŚNE":
                z = new Zadanie(DziedzinaZadania.valueOf(napis));
                break;
            case "DROGA":
                t = new Teren(RodzajTerenu.valueOf(napis));
                break;
            case "SCIEZKA":
                t = new Teren(RodzajTerenu.valueOf(napis));
                break;
            case "WYSOKI_LAS":
                t = new Teren(RodzajTerenu.valueOf(napis));
                break;
            case "NISKI_LAS":
                t = new Teren(RodzajTerenu.valueOf(napis));
                break;
            case "BAGNO":
                t = new Teren(RodzajTerenu.valueOf(napis));
                break;
            default:
                System.out.println("Nieprawidlowy element");
                break;
        }
    }
}
