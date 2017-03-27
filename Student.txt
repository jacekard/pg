package bieg.po.lesie;

import bieg.po.lesie.Czlowiek;
import bieg.po.lesie.RodzajTerenu;
import java.util.Random;

/**
 *
 * @author TB
 */

public class Student extends Czlowiek{
    public final String KierunekStudiow;
    public Student(String imie, String nazwisko, Czlowiek.Plec plec, String KierunekStudiow) {
        super(imie, nazwisko, plec);
        this.KierunekStudiow = KierunekStudiow;
    }
    
    @Override
    public void przedstawSie() {
        wypowiedzSie("Cześć! Jestem "+getImie()+" "+getNazwisko()+". Jestem studentem na kierunku" + KierunekStudiow);
    }
    
    @Override
    public boolean rozwiazZadanie(Zadanie zadanie) {
        Random generator = new Random();
        int chance = generator.nextInt(99);
        if(chance < 20) {
            System.out.println("Dla studenta to proste jak drut!");
            return true;
        }
        else return false;
    }
    
    @Override
    public double predkoscPoruszaniaSie(RodzajTerenu rodzajTerenu) {
 switch (rodzajTerenu) {
            case DROGA:
                wypowiedzSie("Idę sobie drogą.");
                return humorIUwarunkowaniaOsobiste.nextDouble() * 0.2 + 1; //Od 0.8 do 1.0
            case SCIEZKA:
                wypowiedzSie("Co za ładna ścieżka w lesie");
                return humorIUwarunkowaniaOsobiste.nextDouble() * 0.2 + 0.8; //Od 0.6 do 0.8
            case WYSOKI_LAS:
                wypowiedzSie("Idę na przełaj przez las. Może znajdę grzyby?");
                return humorIUwarunkowaniaOsobiste.nextDouble() * 0.2 + 0.8; //Od 0.4 do 0.6
            case NISKI_LAS:
                wypowiedzSie("Strasznie dużo gałęzi. Ciężko się idzie.");
                return humorIUwarunkowaniaOsobiste.nextDouble() * 0.2 + 0.6; //Od 0.2 do 0.4
            case BAGNO:
            default:
                wypowiedzSie("O rany! Gdzie ja jestem?");
                return humorIUwarunkowaniaOsobiste.nextDouble() * 0.2; //Od 0 do 0.2
        }
    }
    
    
    
}
