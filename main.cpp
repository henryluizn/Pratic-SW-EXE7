#include<iostream>
#include <string>
#include "string.h"

#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include "Curso.hpp"


int main(){
		std::string buffer_pessoa;
		std::string buffer_string;
		int buffer_int;

	try
	{
	// criando instancia do objeto do curso
		std::cout << "Criando um novo curso.\n\tInsira o nome do curso: " ;
		getline(std::cin, buffer_string);
		std::cout << "\n\tInsira o ano de criacao do curso: " ;
		std::cin >> buffer_int;

		// criando instancia do objeto pessoa para atribuir como coordenador do curso
		std::cout << "\nCrie uma nova pessoa para se tornar o coordenador do curso " << buffer_string <<" \n\tNome coordenador: ";		
		std::cin >> buffer_pessoa;
		getline(std::cin, buffer_pessoa);
		Pessoa coordenador{buffer_pessoa};

		Curso c1{buffer_string, buffer_int, coordenador};

	// preparando objetos para criar a instancia da disciplina
		std::cout << "\nCriando uma nova disciplina." << std::endl;
		std::cout << "\nCrie uma nova pessoa para se tornar o professor da disciplina\n\tNome professor: ";		
		getline(std::cin, buffer_pessoa);
		Pessoa prof{buffer_pessoa};
		
		std::cout << "Nova pessoa cadastrada: " << prof.getNome() << std::endl;

		std::cout << "\nCriando as pessoas para vincular como alunos(as)" << std::endl;
		std::cout << "\nCriando uma nova pessoa\n\tNome pessoa 1: " ;		
		getline(std::cin, buffer_pessoa);
		Pessoa p1{buffer_pessoa};
		
		std::cout << "Nova pessoa cadastrada: " << p1.getNome() << std::endl;

		
		std::cout << "\nCriando uma nova pessoa\n\tNome pessoa 2: " ;		
		getline(std::cin, buffer_pessoa);
		Pessoa p2{buffer_pessoa};	

		std::cout << "Nova pessoa cadastrada: " << p2.getNome() << std::endl;

		
		Disciplina d1{"Orientacao a Objetos", c1, prof};
		d1.setProfessor(prof);
		
		std::cout << "\nAtribuindo o professor " << d1.getNomeProfessor() << " para a disciplina " << d1.getNome() << std::endl;
		
		std::cout << "\nAdicionando alunos(as) na disciplina" << std::endl;

		
		if (d1.adicionarAluno(&p1))
		{
			std::cout << "\nAluno(a) " << p1.getNome() << " adicionado com sucesso!" << std::endl;		
		}else{
			std::cout << "Falha ao adicionar o aluno(a)" << std::endl;		
		}
		
		if (d1.adicionarAluno(&p2))
		{
			std::cout << "Aluno(a) " << p2.getNome() << " adicionado com sucesso!" << std::endl;		
		}else{
			std::cout << "Falha ao adicionar o aluno(a)" << std::endl;		
		}
		
		
		std::cout << "\nImpressao do vetor de alunos ANTES da atualizacao do nome do 2 aluno: " << std::endl;
		d1.printVetorAlunos();

		std::cout << "\n\tInsira um novo nome para o aluno 2: " ;
		getline(std::cin, buffer_pessoa);
		p2.setNome(buffer_pessoa);

		std::cout << "\nImpressao do vetor de alunos APOS atualizacao do nome do 2 aluno: " << std::endl;
		d1.printVetorAlunos();

		std::cout << "\nO curso " << d1.getCursoDisciplina().getNomeCurso() << " possui o " << 
		d1.getCursoDisciplina().getCoordenadorCurso().getNome() << " como coordenador de curso;" << std::endl;

		std::cout << "\nA disciplina " << d1.getNome() << " ministrada pelo professor " << d1.getNomeProfessor() <<
		" possui um total de " << d1.getQtdAlunos() << " alunos vinculados." << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
