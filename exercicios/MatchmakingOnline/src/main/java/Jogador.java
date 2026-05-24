public class Jogador {
    private int id;
    private String nickname;

    public Jogador(int id, String nickname) {
        this.id = id;
        this.nickname = nickname;
    }

    public int getId() {
        return id;
    }

    public String getNickname() {
        return nickname;
    }

    @Override
    public String toString() {
        return nickname + " (ID: " + id + ")";
    }
}
