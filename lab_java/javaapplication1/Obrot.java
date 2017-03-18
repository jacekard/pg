package javaapplication1;

public class Obrot implements Transformacja {
    private final double angleA;
    
    public Obrot(double angleA) {
        this.angleA = angleA;
    }
    @Override
    public Transformacja getTranformacjaOdwrotna() throws
            BrakTransformacjiOdwrotnejException {
        if (angleA == 0)
            throw new BrakTransformacjiOdwrotnejException("Brak obrotu!");
        return new Obrot(-angleA);
    }

    @Override
    public Punkt transformuj(Punkt p) {
        return new Punkt(p.getX() * Math.cos(angleA) - p.getY() * Math.sin(angleA),
                p.getX() * Math.sin(angleA)+ p.getY() * Math.cos(angleA));
    }

    public double getAngleA() {
        return angleA;
    }

    @Override
    public String toString() {
        return "Obrot o kat " + this.angleA;
    }
    
    
}
