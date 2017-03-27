package bieg.po.lesie;

import java.util.Random;

public class RobotMobilny extends Robot {

    public RobotMobilny(int numerSeryjny) {
        super("Robot mobilny typ A", numerSeryjny);
    }

    @Override
    public boolean rozwiazZadanie(Zadanie zadanie) {
        Random generator = new Random();
        int chance = generator.nextInt(99);
        if(chance < 5) return true;
        else return false;
    }
    
    @Override
    public double predkoscPoruszaniaSie(RodzajTerenu rodzajTerenu) {
        switch(rodzajTerenu)
        {
            case DROGA:
                komunikuj("Wykryto teren: "+rodzajTerenu+". Rozwijanie maksymalnej prędkości.");
                return czynnikiLosowe.nextDouble()*0.1 + 0.95; //Od 0.95 do 1.5
            case SCIEZKA:
                komunikuj("Wykryto teren: "+rodzajTerenu+". Prędkość umiarkowana.");
                return czynnikiLosowe.nextDouble()*0.1 + 0.85; //Od 0.85 do 0.95
            case WYSOKI_LAS:
                komunikuj("Wykryto teren: "+rodzajTerenu+". Nieprzyjazne warunki.");
                return czynnikiLosowe.nextDouble()*0.1 + 0.4; //Od 0.4 do 0.5
            case NISKI_LAS:
                komunikuj("Wykryto teren: "+rodzajTerenu+". Wykryto znaczną liczbę przeszkód.");
                return czynnikiLosowe.nextDouble()*0.2 + 0.2; //Od 0.2 do 0.4
            case BAGNO:
            default:
                komunikuj("Wykryto teren: "+rodzajTerenu+".");
                komunikuj("Awaria silników!");
                return czynnikiLosowe.nextDouble()*0.1; //Od 0.0 do 0.1
        }
    }
    
}
