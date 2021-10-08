#ifndef CURSO_H
#define CURSO_H

#include "Pessoa.hpp"

class Curso
{
    public:
        Curso(std::string nomeCurso, int anoCriacaoCurso, Pessoa& coordenadorCurso);
        std::string getNomeCurso();
        Pessoa& getCoordenadorCurso();

    private:
        std::string nomeCurso;
        int anoCriacaoCurso;
        Pessoa coordenadorCurso;
};

#endif
