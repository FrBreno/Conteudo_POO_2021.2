#include <iostream>
#include <map>
#include <memory>
#include "../Paciente e Medico/pacMed.hpp"

class Hospital
{
  std::map<std::string, std::shared_ptr<IMedico>> medicos;
  std::map<std::string, std::shared_ptr<IPaciente>> pacientes;

public:
  Hospital();
  void addMedico(std::shared_ptr<IMedico> medico);
  void addPaciente(std::shared_ptr<IPaciente> paciente);
  void removerMedico(std::string sender);
  void removerPaciente(std::string sender);
  void vincular(std::string nomeMedico, std::string nomePaciente);
  friend std::ostream &operator<<(std::ostream &os, const Hospital &h); // show all
};