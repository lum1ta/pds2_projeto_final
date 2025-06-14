// Arquivo hpp do cadastro de jogadores no jogo Flappy Bird com Allegro
#ifndef CADASTRO_H
#define CADASTRO_H

#include <string>
#include <vector>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

using namespace std;

// Struct Jogador com adições para Allegro
struct Jogador {
    // Atributos do jogador
    string apelido_unico;
    string nome;

    // Estatísticas do jogador
    int pontuacao;
    int vitorias;
    int derrotas;
    int melhor_pontuacao;  // Novo campo para armazenar o recorde

    // Elementos gráficos do Allegro
    ALLEGRO_COLOR cor;          // Cor associada ao jogador
    ALLEGRO_BITMAP* avatar;     // Avatar do jogador (opcional)
};

// Classe cadastro com integração Allegro
class Cadastro {
private:
    vector<Jogador> jogadores;
    ALLEGRO_FONT* fonte;        // Fonte para exibição de texto
    
    // Métodos auxiliares
    bool apelido_existe(const string& apelido) const;
    void ordenar_por_pontuacao();

public:
    // Construtor e Destrutor
    Cadastro(ALLEGRO_FONT* fonte = nullptr);
    ~Cadastro();

    // Gerenciamento dos Jogadores
    bool cadastrar_jogador(const string& apelido_unico, const string& nome = "", 
                          ALLEGRO_COLOR cor = al_map_rgb(255, 255, 255));
    bool trocar_apelido(const string& apelido_antigo, const string& apelido_novo);
    bool remover_jogador(const string& apelido_unico);
    bool carregar_avatar(const string& apelido_unico, const string& caminho_imagem);

    // Gerenciamento de Estatísticas
    bool incrementar_pontuacao(const string& apelido_unico, int pontuacao);
    void incrementar_vitorias(const string& apelido_unico);
    void incrementar_derrotas(const string& apelido_unico);
    void resetar_estatisticas(const string& apelido_unico);

    // Consulta 
    const Jogador* buscar_jogador(const string& apelido_unico) const;
    const vector<Jogador>& obter_ranking() const;
    void exibir_jogadores(int x, int y, ALLEGRO_DISPLAY* display) const;

    // Operações com arquivo
    bool salvar_jogadores(const string& arquivo) const;
    bool carregar_jogadores(const string& arquivo);

    // Configuração Allegro
    void definir_fonte(ALLEGRO_FONT* nova_fonte);
};
#endif