/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bieg.po.lesie;

import java.util.Random;

public class TerminatorL extends Terminator {

    public TerminatorL(int numerSeryjny) {
        super(numerSeryjny);
    }

    @Override
    public boolean rozwiazZadanie(Zadanie zadanie) {
        Random generator = new Random();
        int chance = generator.nextInt(99);
        if (zadanie.dziedzina == DziedzinaZadania.MATEMATYKA
                || zadanie.dziedzina == DziedzinaZadania.FIZYKA || zadanie.dziedzina == DziedzinaZadania.INFORMATYKA) {
            return true;
        } else if (zadanie.dziedzina == DziedzinaZadania.NAUKI_LEŚNE && chance < 60) {
            return true;
        } else if (zadanie.dziedzina == DziedzinaZadania.SZTUKA && chance < 5) {
            return true;
        } else {
            return false;
        }
    }

    @Override
    public double predkoscPoruszaniaSie(RodzajTerenu rodzajTerenu) {
        switch (rodzajTerenu) {
            case DROGA:
                komunikuj("Wykryto teren: " + rodzajTerenu + ". Rozwijanie maksymalnej prędkości.");
                return czynnikiLosowe.nextDouble() * 0.1 + 1.1; //Od 0.95 do 1.5
            case SCIEZKA:
                komunikuj("Wykryto teren: " + rodzajTerenu + ". Prędkość umiarkowana.");
                return czynnikiLosowe.nextDouble() * 0.1 + 0.9; //Od 0.85 do 0.95
            case WYSOKI_LAS:
                komunikuj("Wykryto teren: " + rodzajTerenu + ". Nieprzyjazne warunki.");
                return czynnikiLosowe.nextDouble() * 0.1 + 0.5; //Od 0.4 do 0.5
            case NISKI_LAS:
                komunikuj("Wykryto teren: " + rodzajTerenu + ". Wykryto znaczną liczbę przeszkód.");
                return czynnikiLosowe.nextDouble() * 0.2 + 0.3; //Od 0.2 do 0.4
            case BAGNO:
            default:
                komunikuj("Wykryto teren: " + rodzajTerenu + ".");
                komunikuj("Awaria silników!");
                return czynnikiLosowe.nextDouble() * 0.1; //Od 0.0 do 0.1
        }
    }

}
