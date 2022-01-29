#include <iostream>
#include <vector>
#include <map>

class IMedico;

class IPaciente
{
public:
  virtual void addMedico(IMedico *) = 0;
  virtual std::string getDiagnotisco() const = 0;
  virtual std::string getId() const = 0;
  virtual std::vector<IMedico *> getMedicos() const = 0;
  virtual void removerMedico(std::string) = 0;
  virtual ~IPaciente(){};
  friend std::ostream &operator<<(std::ostream &os, IPaciente &p);
};

class IMedico
{
public:
  virtual void addPaciente(IPaciente *) = 0;
  virtual std::string getClasse() const = 0;
  virtual std::string getId() const = 0;
  virtual std::vector<IPaciente *> getPacientes() const = 0;
  virtual void removerPaciente(std::string) = 0;
  virtual ~IMedico(){};
  friend std::ostream &operator<<(std::ostream &os, IMedico &m);
};

class Medico : public IMedico
{
private:
  std::string sender{}; // Id
  std::string classe{};
  std::map<std::string, IPaciente *> pacientes;

public:
  Medico(std::string sender, std::string classe);
  void addPaciente(IPaciente *paciente) override;
  std::string getClasse() const override;
  std::string getId() const override;
  std::vector<IPaciente *> getPacientes() const override;
  void removerPaciente(std::string idPaciente) override;
};

class Paciente : public IPaciente
{
protected:
  std::string sender{}; // Id
  std::string diagnostico{};
  std::map<std::string, IMedico *> medicos;

public:
  Paciente(std::string sender, std::string diagnostico);
  void addMedico(IMedico *medico) override;
  std::string getDiagnotisco() const override;
  std::string getId() const override;
  std::vector<IMedico *> getMedicos() const override;
  void removerMedico(std::string idMedico) override;
};