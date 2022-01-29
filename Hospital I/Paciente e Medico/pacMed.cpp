#include <iostream>
#include <memory>
#include "pacMed.hpp"

// MÉDICO:
Medico::Medico(std::string sender, std::string classe) : sender{sender}, classe{classe} {}

void Medico::addPaciente(IPaciente *paciente)
{
  auto key = paciente->getId();
  if (this->pacientes.find(key) != this->pacientes.end())
  {
    return;
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

// // PACIENTE:
Paciente::Paciente(std::string sender, std::string diagnostico) : sender{sender}, diagnostico{diagnostico} {}

void Paciente::addMedico(IMedico *medico)
{
  auto key = medico->getId();
  if (this->medicos.find(key) != this->medicos.end())
  {
    return;
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

std::ostream &operator<<(std::ostream &os, IPaciente &p)
{
  os << "Pac: " << p.getId() << ":" << p.getDiagnotisco() << "\t";
  os << "Meds: [";
  auto meds = p.getMedicos();
  int cont = meds.size();
  for (auto med : meds)
  {
    cont--;
    os << med->getId();
    if (cont > 0)
    {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

std::ostream &operator<<(std::ostream &os, IMedico &m)
{
  os << "Med: " << m.getId() << ":" << m.getClasse() << "\t";
  os << "Pacs: [";
  auto pacs = m.getPacientes();
  int cont = pacs.size();
  for (auto pac : pacs)
  {
    cont--;
    os << pac->getId();
    if (cont > 0)
    {
      os << ", ";
    }
  }
  os << "]";
  return os;
}