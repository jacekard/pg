package bieg.po.lesie;

public interface ElementTrasy {
    Iterable<Uczestnik> getUczestnicy();
    void dodajUczestnika(Uczestnik u);
    void usunUczestnika(Uczestnik u);
    public int getLiczbaUczestnikowNaTrasie();
}
