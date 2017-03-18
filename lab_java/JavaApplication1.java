package javaapplication1;

//import javaapplication1.Translacja;
//import javaapplication1.Skalowanie;
//import javaapplication1.BrakTransformacjiOdwrotnejException;
//import javaapplication1.Punkt;
//import javaapplication1.Transformacja;
public class JavaApplication1 {

    public static void main(String[] args) {

        try {
            Punkt p1 = Punkt.E_X;
            System.out.println(p1);
            Transformacja tr = new Translacja(5, 6);
            System.out.println(tr);
            Punkt p2 = tr.transformuj(p1);
            System.out.println(p2);
            Transformacja trr = tr.getTranformacjaOdwrotna();
            System.out.println(trr);
            Punkt p3 = trr.transformuj(p2);
            System.out.println(p3);

        } catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
        System.out.println();

        try {
            Punkt p1 = new Punkt(2, 2);
            System.out.println(p1);
            Transformacja tr2 = new Skalowanie(5, 4);
            System.out.println(tr2);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTranformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
        System.out.println();

        try {
            Punkt p1 = new Punkt(2, 2);
            Transformacja tr2 = new Skalowanie(5, 0);
            System.out.println(tr2);
            System.out.println(p1);
            Punkt p2 = tr2.transformuj(p1);
            System.out.println(p2);
            Transformacja trr2 = tr2.getTranformacjaOdwrotna();
            System.out.println(trr2);
            Punkt p3 = trr2.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
        System.out.println();
    
            try {
            Punkt p1 = new Punkt(2, 0);
            Transformacja ob = new Obrot(90);
            System.out.println(p1);
            System.out.println(ob);
            Punkt p2 = ob.transformuj(p1);
            System.out.println(p2);
            Transformacja ob2 = ob.getTranformacjaOdwrotna();
            System.out.println(ob2);
            Punkt p3 = ob2.transformuj(p2);
            System.out.println(p3);
        } catch (BrakTransformacjiOdwrotnejException ex) {
            ex.printStackTrace();
        }
        System.out.println();    
        
        
        
        
        
        
        
        /*Działanie klasy Punkt*/
/*      Punkt a1 = new Punkt(3,5);
        Punkt a2 = new Punkt(3,5);
        
        System.out.println(a1);
        System.out.println("X = " + a1.getX());
        System.out.println("Y = " + a1.getY());
        System.out.println("Porównywanie referencji a1 == a1");
        System.out.println(a1 == a1);
        System.out.println("Porównywanie referencji a1 == a2");
        System.out.println(a1 == a2);
        System.out.println("Metoda equals: a1.equals(a1)");
        System.out.println(a1.equals(a1));
        System.out.println("Metoda equals: a1.equals(a2)");
        System.out.println(a1.equals(a2));
        System.out.println("Metoda hashCode: a1.hashCode()");
        System.out.println(a1.hashCode());
        System.out.println("Metoda hashCode: a2.hashCode()");
        System.out.println(a2.hashCode());
*/
    }
}