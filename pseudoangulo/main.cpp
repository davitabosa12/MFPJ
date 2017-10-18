#include<iostream>
#include"vec2.h"
#include"pseudoangulo.h"
void imprimeAngEntre(Vec2 v1, Vec2 v2);
void imprimeAng(Vec2 v1);
void pause();
int main(){
  std::cout<<"Pseudoangulo"<<std::endl;
      std::string v1,v2;
      bool operating = true;
  while(operating){
    std::cout<<"Selecione o modo:\n[1]Pseudoangulo entre vetor e (1,0)\n[2]Pseudoangulo entre dois vetores\n[3]Sair"<<std::endl;
    std::string temp;
    std::cin >> temp;
    int op = std::stoi(temp);
    switch(op){
    case 1:{
      std::cout << "Insira o vetor. Ex: 12,44" << std::endl;
	std::cin >> v1;
	imprimeAng(Vec2(v1));
	break;
      }
    case 2:{
      std::cout << "Insira o primeiro vetor. Ex: 12,44" << std::endl;
	std::cin >> v1;
	std::cout << "Insira o segundo vetor." << std::endl;
	std::cin >> v2;
	imprimeAngEntre(Vec2(v1),Vec2(v2));
	break;
      }
    case 3:{
      std::cout << "Saindo..." << std::endl;
      operating = false;
      break;
    }
    default:{
      std::cout << "Opcao invalida" << std::endl;
    }
    }
  }
}

void imprimeAngEntre(Vec2 v1, Vec2 v2){
  double result = PAngleBetween(v1,v2);
  double x1 = v1.getX(), y1 = v1.getY();
  double x2 = v2.getX(), y2 = v2.getY();
  std::cout << "(" << x1 << "," << y1 << "):";
  std::cout << "(" << x2 << "," << y2 << ")" << " "<< result << std::endl;
  pause();
}
void imprimeAng(Vec2 v1){
  double result = PAngle(v1);
  double x1 = v1.getX(), y1 = v1.getY();
  std::cout << "(" << x1 << "," << y1 << ")" << " "<< result << std::endl;
  pause();
}

void pause(){
  std::cout << "Pressione ENTER para continuar"<<std::endl;
  std::cin.get();
  std::cin.get();
  std::cout <<std::endl;
}
