#include "hospital.hpp"

Hospital::Hospital() {}

void Hospital::addMedico(std::shared_ptr<IMedico> medico)
{
  auto key = medico->getId();
  if (this->medicos.find(key) != this->medicos.end())
  {
    throw std::runtime_error("O medico ja esta cadastrado no hospital.");
  }
  this->medicos[key] = medico;
}

void Hospital::addPaciente(std::shared_ptr<IPaciente> paciente)
{
  auto key = paciente->getId();
  if (this->pacientes.find(key) != this->pacientes.end())
  {
    throw std::runtime_error("O paciente ja esta cadastrado no hospital.");
  }
  this->pacientes[key] = paciente;
}

void Hospital::removerMedico(std::string sender)
{
  auto it = this->medicos.find(sender);
  if (it == this->medicos.end())
  {
    throw std::runtime_error("Medico nao encontrado.");
  }
  this->medicos.erase(it);
}

void Hospital::removerPaciente(std::string sender)
{
  auto it = this->pacientes.find(sender);
  if (it == this->pacientes.end())
  {
    throw std::runtime_error("Paciente nao encontrado.");
  }
  this->pacientes.erase(it);
}

void Hospital::vincular(std::string nomeMedico, std::string nomePaciente)
{
  auto it_pac = this->pacientes.find(nomePaciente);
  auto it_med = this->medicos.find(nomeMedico);

  if (it_pac == this->pacientes.end() || it_med == this->medicos.end())
  {
    throw std::runtime_error("Vinculacao falha! Verifique se o paciente e o medico estao cadastrados nesse hospital.");
  }

  it_pac->second->addMedico(&(*it_med->second));
}

std::ostream &operator<<(std::ostream &os, const Hospital &h)
{
  for (auto &pac : h.pacientes)
  {
    os << *pac.second << "\n";
  }
  for (auto &med : h.medicos)
  {
    os << *med.second << "\n";
  }
  return os;
}
