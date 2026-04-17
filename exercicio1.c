struct Livros {
    char titulo[100];
    char nomeAutor[50];
    int AnoPublicacao;
    int NumPaginas;
    
} livro;

 int main(){
    struct Livros livro1 = {"Dom quixote","Miguel Cervantes",1990,1980 };
    struct Livros livro2 = {"JoãoDev","João Guilherme", 2026, 1};

    printf("Livro 1: \n  titulo: %s\n nomeAutor : %s\n anoPublicacao: %d\n NumPaginas: %d  ", livro1.titulo, livro1.nomeAutor,
    livro1.AnoPublicacao, livro1.NumPaginas);
    printf("Livro 2: \n  titulo: %s\n nomeAutor : %s\n anoPublicacao: %d\n NumPaginas: %d  ", livro2.titulo, livro2.nomeAutor,
    livro2.AnoPublicacao, livro2.NumPaginas);

    
    return 0;
}
