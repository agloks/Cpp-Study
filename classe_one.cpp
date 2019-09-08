  #include <iostream>
  #include <string>

 class Persona //criando minha classe
 {
    private: 
    /*private explicito, porém o padrão ja é private quando omitido,
    no private, no private funciona como uma função de escopo local, 
    somente seus próprios atribuitos e metódos podem ser acessados por dentro*/
      std::string theName;
    public:
      Persona(std::string name);//construtor não padrão
      std::string getName(void) //função que retorna minha variavel local
      {
        return theName;
      };
 };

 Persona::Persona(std::string name)//construindo o construtor, necessário quando não se é o padrão omitido
 {
   theName = name;//embora a variavel esteja fora do escopo, a função é publica do construtor, por isso é possivel modifica-la
 };

 int main(void)
 {
   /*fazendo a instancia do meu objeto
   existem varias maneiras de instacilas,
   nessa maneira estou chamando com um ponteiro,
   a keyword new faz com que ela seja armazenada no heap da memoria*/
   Persona *viking = new Persona("Ragnar");
   

   //o acesso de metódos com instancias feita em ponteiro, se é usando ->
   std::cout << viking -> getName() << std::endl;

  //instancias feita com a keyword new, o gerenciamento da memoria é manual, sendo necessario o uso do delete para libera-lo da memória
   delete viking;

  /*aqui da para ver que embora eu tenha usado deleta no ponteiro viking acima,
  o ponteiro ainda existe, mas não seu conteudo, então posso reutiliza o ponteiro*/
   viking = new Persona("Loki");

   std::cout << viking -> getName() << std::endl;

   delete viking;
   
   return 0;
}