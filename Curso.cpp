#include "Curso.hpp"
#include "Pessoa.hpp"
#include "Disciplina.hpp"
#include <iostream>

Curso::Curso(std::string nomeCurso, int anoCriacaoCurso, Pessoa& coordenadorCurso)
    :nomeCurso{nomeCurso}, anoCriacaoCurso{anoCriacaoCurso}, coordenadorCurso{coordenadorCurso}
{

}  
        
std::string Curso::getNomeCurso()
{
    return this->nomeCurso;
}

Pessoa& Curso::getCoordenadorCurso()
{
    return this->coordenadorCurso;
}