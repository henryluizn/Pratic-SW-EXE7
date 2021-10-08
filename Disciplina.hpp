#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#include <string>
#include "Pessoa.hpp"
#include "Curso.hpp"



class Disciplina{
	public:
	//construtor da classe
		Disciplina(std::string nome, Curso& cursoDisciplina, Pessoa& professor);
		
		std::string getNome();
		void setNome(std::string nome);
		
		int getCargaHoraria();
		void setCargaHoraria(unsigned int cargaHoraria);

		Pessoa& getProfessor();
		void setProfessor(Pessoa& professor);
		
	// -------- novas implementacoes ------------
		std::string getNomeProfessor();
		bool adicionarAluno(Pessoa* alunos);
		Pessoa** getVetorAlunos();
		void inicializaArray();
		int getQtdAlunos();
		void printVetorAlunos();
		Curso getCursoDisciplina();

	// ------------------------------------------	
	private:
		std::string nome;
		unsigned short int cargaHoraria;
	// -------- novas implementacoes ------------
		Pessoa* alunos[50];
		Curso cursoDisciplina;
		Pessoa professor;
		int qtd_alunos;
	// ------------------------------------------	

};
#endif
