package bieg.po.lesie;

public class ZwyklaKlasa {

    private static int liczbaInstancji = 0;
    private int numerInstancji;

    private class KlasaWewnetrzna implements SluchaczZdarzen {

        private int poleKlasyWewnetrznej;

        public KlasaWewnetrzna(int poleKlasyWewnetrznej) {
            this.poleKlasyWewnetrznej = poleKlasyWewnetrznej;
        }

        @Override
        public void wystapiloZdarzenie(int priorytet, String nazwa) {
            System.out.println("KlasaWewnetrzna obsługuje zdarzenie "
                    + nazwa + " o priorytecie " + priorytet);
            System.out.println("Wartosci pól:");
            System.out.println("liczbaInstancji: " + liczbaInstancji);
            System.out.println("numerInstancji: " + numerInstancji);
            System.out.println("poleKlasyWewnentrznej: " + poleKlasyWewnetrznej);
        }
    }

    private static class StatycznaKlasaWewnetrzna implements SluchaczZdarzen {

        private int poleStatyczneKlasyWewnetrznej;

        public StatycznaKlasaWewnetrzna(int p) {
            this.poleStatyczneKlasyWewnetrznej = p;
        }

        @Override
        public void wystapiloZdarzenie(int priorytet, String nazwa) {
            System.out.println("StatycznaKlasaWewnetrzna"
                    + "obsługuje zdarzenie " + nazwa
                    + " o priorytecie " + priorytet);
            System.out.println("Wartosci pól:");
            System.out.println("liczbaInstancji: " + liczbaInstancji);
            //Brak dostępu do pola numerInstancji - klasa wewnętrzna jest statycza
            //System.out.println("numerInstancji: "+ numerInstancji);
            System.out.println("poleStatycznejKlasyWewnentrznej: " + poleStatyczneKlasyWewnetrznej);
        }
    }

    public ZwyklaKlasa() {
        liczbaInstancji++;
        numerInstancji = liczbaInstancji;
    }

    public SluchaczZdarzen klasaWewnetrzna() {
        return new KlasaWewnetrzna(2 * numerInstancji);
    }

    public SluchaczZdarzen statycznaKlasaWewnetrzna() {
        return new StatycznaKlasaWewnetrzna(3 * liczbaInstancji);
    }

    public SluchaczZdarzen klasaAnonimowa() {
        /**
         * Obiekt klasy anonimowej tworzony w metodzie obiektu nadrzędnego ma
         * dostęp do wszystkich pól i metod analogicznie do klasy wewnętrznej.
         * Klasy anonimowe mogą być utworzone na bazie każdej klasy po której
         * można dziedziczyć, bądź interfejsu. Najczęściej jednak klasy te są
         * tworzone na bazie klas abstrakcyjnych i interfejsów.
         */
        return new SluchaczZdarzen() {
            int poleKlasyAnonimowej = 5 * numerInstancji;

            @Override
            public void wystapiloZdarzenie(int priorytet, String nazwa) {
                System.out.println("KlasaAnonimowa obsługuje zdarzenie "
                        + nazwa + " o priorytecie " + priorytet);
                System.out.println("Wartosci pól:");
                System.out.println("liczbaInstancji: " + liczbaInstancji);
                System.out.println("numerInstancji: " + numerInstancji);
                System.out.println("poleKlasyAnonimowej: "
                        + poleKlasyAnonimowej);
            }
        };
    }

    public SluchaczZdarzen wyrazenieLambda() {
        /**
         * Wyrażenia lambda wprowadzono w Javie 8. Można przyjąć, że jest to
         * skrócona wersja klasy anonimowej dla interfejsu oznaczonego andotacją
         *
         * @FunctionalInterface
         */
        return (int p, String n) -> {
            System.out.println("Wyrażenie Lambda obsługuje zdarzenie "
                    + n + " o priorytecie " + p);
            System.out.println("Wartosci pól:");
            System.out.println("liczbaInstancji: " + liczbaInstancji);
            System.out.println("numerInstancji: " + numerInstancji);
        };
    }

    public void zwyklaMetoda(int priorytet, String nazwa) {
        System.out.println("zwyklaMetoda obsługuje zdarzenie " + nazwa
                + " o priorytecie " + priorytet);
        System.out.println("Wartosci pól:");
        System.out.println("liczbaInstancji: " + liczbaInstancji);
        System.out.println("numerInstancji: " + numerInstancji);
    }

    public static void zwyklaStatycznaMetoda(int priorytet,
            String nazwa) {
        System.out.println("zwyklaStatycznaMetoda obsługuje zdarzenie "
                + nazwa + " o priorytecie " + priorytet);
        System.out.println("Wartosci pól:");
        System.out.println("liczbaInstancji: " + liczbaInstancji);
    }

}
