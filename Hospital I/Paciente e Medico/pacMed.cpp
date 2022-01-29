#include <iostream>
#include "pacMed.hpp"

// MÉDICO:
Medico::Medico(std::string sender, std::string classe) : classe{classe}, sender{sender} {}

void Medico::addPaciente(IPaciente *paciente)
{
  auto key = paciente->getId();
  if (this->pacientes.find(key) != this->pacientes.end())
  {
    throw std::runtime_error("O paciente ja esta cadastrado!");
  }
  this->pacientes[key] = paciente;
  paciente->addMedico(this);
}

std::string Medico::getClasse() const
{
  return this->classe;
}

std::string Medico::getId() const
{
  return this->sender;
}

std::vector<IPaciente *> Medico::getPacientes() const
{
  std::vector<IPaciente *> result;

  for (auto &paciente : this->pacientes)
  {
    result.push_back(paciente.second);
  }
  return result;
}

void Medico::removerPaciente(std::string idPaciente)
{
  auto it = this->pacientes.find(idPaciente);
  if (it == this->pacientes.end())
  {
    throw std::runtime_error("Paciente nao encontrado.");
  }
  IPaciente *paciente = it->second;
  this->pacientes.erase(it);
  paciente->removerMedico(this->sender);
}

std::ostream &operator<<(std::ostream &os, Medico &m)
{
  os << "Med: " << m.sender << ":" << m.classe << "Pacs: [";
  int cont = (int)m.pacientes.size();
  for (auto pac : m.pacientes)
  {
    cont--;
    os << pac.second->getId();
    if (cont != 0)
    {
      os << ",";
    }
    os << " ";
  }
  os << "]";
  return os;
}

// // PACIENTE:
Paciente::Paciente(std::string sender, std::string diagnostico) : diagnostico{diagnostico}, sender{sender} {}

void Paciente::addMedico(IMedico *medico)
{
  auto key = medico->getId();
  if (this->medicos.find(key) != this->medicos.end())
  {
    throw std::runtime_error("O medico ja esta cadastrado!");
  }

  auto getMed = getMedicos();
  for (auto &med : getMed)
  {
    std::string especialidade = medico->getClasse();
    if (med->getClasse() == especialidade)
    {
      throw std::runtime_error("Ja existe outro medico com a especialidade " + especialidade + " para o paciente " + this->sender);
    }
  }

  this->medicos[key] = medico;
  medico->addPaciente(this);
}

std::string Paciente::getDiagnotisco() const
{
  return this->diagnostico;
}

std::string Paciente::getId() const
{
  return this->sender;
}

std::vector<IMedico *> Paciente::getMedicos() const
{
  std::vector<IMedico *> result;
  for (auto &medico : this->medicos)
  {
    result.push_back(medico.second);
  }
  return result;
}

void Paciente::removerMedico(std::string idMedico)
{
  auto it = this->medicos.find(idMedico);
  if (it == this->medicos.end())
  {
    throw std::runtime_error("Medico nao encontrado.");
  }
  IMedico *medico = it->second;
  this->medicos.erase(it);
  medico->removerPaciente(this->sender);
}

std::ostream &operator<<(std::ostream &os, Paciente &p)
{
  os << "Pac: " << p.sender << ":" << p.diagnostico << "Meds: [";
  int cont = (int)p.medicos.size();
  for (auto med : p.medicos)
  {
    cont--;
    os << med.second->getId();
    if (cont != 0)
    {
      os << ",";
    }
    os << " ";
  }
  os << "]";
  return os;
}