#include "Disciplina.hpp"
#include "Pessoa.hpp"
#include <iostream>

// construtor modificado
Disciplina::Disciplina(std::string nome, Curso& cursoDisciplina, Pessoa& professor)
	:nome{nome}, cursoDisciplina{cursoDisciplina}, professor{professor}, qtd_alunos{0}{
}

std::string Disciplina::getNome(){
	return this->nome;
}

void Disciplina::setNome(std::string nome){
	this->nome = nome;
}

int Disciplina::getCargaHoraria(){
	return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(unsigned int cargaHoraria){
	this->cargaHoraria = cargaHoraria;
}


Pessoa& Disciplina::getProfessor()
{
	return this->professor;
}


void Disciplina::setProfessor(Pessoa& professor)
{
	this->professor = professor;
}


// -------- novas implementacoes ------------	

std::string Disciplina::getNomeProfessor()
{
	return this->getProfessor().getNome();
}
	
int Disciplina::getQtdAlunos(){
	return this-> qtd_alunos;
}

bool Disciplina::adicionarAluno(Pessoa* aluno)
{
	try
	{
		this->alunos[this->qtd_alunos] = aluno;
		this->qtd_alunos+=1;

		return true;
	}
	catch(const std::exception& e)
	{
		return false;
	}
}

Pessoa** Disciplina::getVetorAlunos()
{
	return this->alunos;
}


void Disciplina::printVetorAlunos(){
	try{
		Pessoa** aluno_atual{getVetorAlunos()};
		for (int i = 0; i < this->getQtdAlunos(); i++)
		{
			std::cout << "\t- Aluno: " << aluno_atual[i]->getNome() << std::endl;
		}
	}catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

Curso Disciplina::getCursoDisciplina()
{
	return this->cursoDisciplina;
}



// ------------------------------------------	
