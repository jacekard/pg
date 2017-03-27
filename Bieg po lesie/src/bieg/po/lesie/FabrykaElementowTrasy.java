package bieg.po.lesie;

public class FabrykaElementowTrasy {

    public FabrykaElementowTrasy() {

    }

    public static Teren utworzElementTrasy(RodzajTerenu rt) {
        Teren T = new Teren(rt);
        return T;
    }

    public static Zadanie utworzElementTrasy(DziedzinaZadania dz) {
        Zadanie Z = new Zadanie(dz);
        return Z;
    }

    public static ElementTrasy utworzElementTrasy(String s)
            throws BrakElementu {
        try {
            DziedzinaZadania dz = DziedzinaZadania.valueOf(s);
            Zadanie Z = utworzElementTrasy(dz);
            return Z;
        } catch (IllegalArgumentException ex) {
            //throw new BrakElementu(ex.getMessage(), ex.getCause());
        }

        try {
            RodzajTerenu tr = RodzajTerenu.valueOf(s);
            Teren T = utworzElementTrasy(tr);
            return T;
        } catch (IllegalArgumentException ex) {
            throw new BrakElementu(ex.getMessage(), ex.getCause());
        }
    }
}