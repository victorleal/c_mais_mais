/* 
 * File:   Interfaces.cpp
 * Author: victorleal
 * 
 * Created on 14 de Outubro de 2012, 23:14
 */

#include "Interfaces.h"
#include "PagamentoCartao.h"
#include "PagamentoBoleto.h"

Interfaces::Interfaces() {
}

void Interfaces::cadastrarCliente() {
    Cliente c;
    string nome, telefone, endereco, email, cpf;

    cout << "\nCadastro Cliente";

    cout << "\n\tDigite o nome: ";
    limpaBuffer();
    getline(cin, nome);
    c.setNome(nome);

    cout << "\n\tDigite o CPF: ";
    getline(cin, cpf);
    c.setCpf(cpf);

    cout << "\n\tDigite o endereco: ";
    getline(cin, endereco);
    c.setEndereco(endereco);

    cout << "\n\tDigite o telefone: ";
    getline(cin, telefone);
    c.setTelefone(telefone);

    cout << "\n\tDigite o e-mail: ";
    getline(cin, email);
    c.setEmail(email);

    c.create();

}

void Interfaces::cadastrarEspetaculo() {
    Espetaculo e;
    string titulo, descricao, diretor, elenco, dataHora;
    float precoBilhete;

    cout << "\nCadastro Espetaculo" << endl;

    cout << "\n\tDigite o titulo: " << endl;
    limpaBuffer();
    getline(cin, titulo);
    e.setTitulo(titulo);

    cout << "\n\tDigite a descricao: " << endl;
    getline(cin, descricao);
    e.setDescricao(descricao);

    cout << "\n\tDigite o diretor: " << endl;
    getline(cin, diretor);
    e.setDiretor(diretor);

    cout << "\n\tDigite o elenco (separe por virgulas): " << endl;
    getline(cin, elenco);
    e.setElenco(elenco);

    cout << "\n\tDigite o preco do bilhete: " << endl;
    scanf("%f", &precoBilhete);
    e.setPrecoBilhete(precoBilhete);

    cout << "\n\tDigite a data e a hora (formato dd/mm/aaaa hh:mm:ss) : " << endl;
    limpaBuffer();
    getline(cin, dataHora);
    TypeConverter tc;
    e.setDataHorario(tc.convertStringToTime(dataHora));

    e.create();
}

void Interfaces::cadastrarBilhete() {
    Bilhete b;
    Cliente c;
    Pagamento p;
    Espetaculo e;
    FormaPagamento *fp;

    int idCliente, idEspetaculo, tipoPagamento;
    string data, valor, bandeira, numeroCartao, banco, codigoBarras;
    TypeConverter tc;

    cout << "Cadastro Bilhete" << endl;

    cout << "Selecione o cliente: " << endl;
    c.listar();
    cout << "Id do Cliente: " << endl;
    cin >> idCliente;

    cout << "Selecione o espetaculo: " << endl;
    e.listar();
    cout << "Id do Espetaculo: " << endl;
    cin >> idEspetaculo;

    c.setId(idCliente);
    e.setId(idEspetaculo);

    c.read();
    e.read();

    //PAGAMENTO
    cout << "Data e Hora (formato dd/mm/aaaa hh:mm:ss): " << endl;
    limpaBuffer();
    getline(cin, data);
    p.setDataPagamento(tc.convertStringToTime(data));
    
    cout << "Valor: " << endl;
    getline(cin, valor);
    p.setValor(tc.convertStringToFloat(valor));

    do {
        cout << "Forma de pagamento: " << endl;
        cout << "1 - Cartao" << endl;
        cout << "2 - Boleto" << endl;
        cin >> tipoPagamento;

    } while (tipoPagamento != 1 and tipoPagamento != 2);

    if (tipoPagamento == 1) {
        cout << "Bandeira: " << endl;
        limpaBuffer();
        getline(cin, bandeira);
        cout << "Numero do Cartao: " << endl;
        getline(cin, numeroCartao);

        fp = new PagamentoCartao(bandeira, numeroCartao);
    }
    else if (tipoPagamento == 2) {
        cout << "Banco : " << endl;
        limpaBuffer();
        getline(cin, banco);
        cout << "Codigo de Barras: " << endl;
        getline(cin, codigoBarras);

        fp = new PagamentoBoleto(banco, codigoBarras);
    }
    fp->create();
    
    p.setFormaPagamento(fp);
    p.create();

    b.setCliente(c);
    b.setPagamento(p);
    b.setEspetaculo(e);
    b.create();

}

void Interfaces::editarCliente() {
    Cliente c;
    int id;
    string nome, telefone, endereco, email, cpf;

    cout << "ID do Cliente: ";
    cin.clear();
    cin >> id;

    c.setId(id);
    c.show();

    cout << "Alteracao do Cliente - ID: " << c.getId() << endl;

    cout << "\n\tDigite o nome: ";
    limpaBuffer();
    getline(cin, nome);
    c.setNome(nome);

    cout << "\n\tDigite o CPF: ";
    getline(cin, cpf);
    c.setCpf(cpf);

    cout << "\n\tDigite o endereco: ";
    getline(cin, endereco);
    c.setEndereco(endereco);

    cout << "\n\tDigite o telefone: ";
    getline(cin, telefone);
    c.setTelefone(telefone);

    cout << "\n\tDigite o e-mail: ";
    getline(cin, email);
    c.setEmail(email);

    c.update();
}

void Interfaces::editarEspetaculo() {
    Espetaculo e;
    int id;
    string titulo, descricao, diretor, elenco, dataHora;
    float precoBilhete;

    cout << "ID do Espetaculo: ";
    cin.clear();
    cin >> id;

    e.setId(id);
    e.show();

    if (e.getId() != -1) {

        cout << "Alteracao do Espetaculo - ID: " << e.getId() << endl;

        cout << "\n\tDigite o titulo: " << endl;
        limpaBuffer();
        getline(cin, titulo);
        e.setTitulo(titulo);

        cout << "\n\tDigite a descricao: " << endl;
        getline(cin, descricao);
        e.setDescricao(descricao);

        cout << "\n\tDigite o diretor: " << endl;
        getline(cin, diretor);
        e.setDiretor(diretor);

        cout << "\n\tDigite o elenco (separe por virgulas): " << endl;
        getline(cin, elenco);
        e.setElenco(elenco);

        cout << "\n\tDigite o preco do bilhete: " << endl;
        scanf("%f", &precoBilhete);
        e.setPrecoBilhete(precoBilhete);

        cout << "\n\tDigite a data e a hora (formato dd/mm/aaaa hh:mm:ss) : " << endl;
        limpaBuffer();
        getline(cin, dataHora);
        TypeConverter tc;
        e.setDataHorario(tc.convertStringToTime(dataHora));

        e.update();
    }
}

void Interfaces::editarBilhete() {
}

void Interfaces::excluirCliente() {
    Cliente c;
    int id;

    cout << "ID do Cliente: " << endl;
    cin.clear();
    cin >> id;

    c.setId(id);
    c.deleting();
    limpaBuffer();
}

void Interfaces::excluirEspetaculo() {
    Espetaculo e;
    int id;

    cout << "ID do Espetaculo: " << endl;
    cin.clear();
    cin >> id;

    e.setId(id);
    e.deleting();
    limpaBuffer();
}

void Interfaces::excluirBilhete() {
}

void Interfaces::listarCliente() {
    /* Cliente c2;
     c2.setId(2);
     c2.read();
     cout << "\nNome: " << c2.getNome() << "\n";
     cout << "\nSei la: " << c2.getCpf() << "\n";*/

}

void Interfaces::listarEspetaculo() {
}

void Interfaces::listarBilhete() {
}

Interfaces::Interfaces(const Interfaces& orig) {
}

Interfaces::~Interfaces() {
}

void Interfaces::limpaBuffer() {
    scanf("%*[^\n]");
    scanf("%*c");
}
