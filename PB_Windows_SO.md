# Pesquisa Bibliográfica - Sistema Operacional
-------------
# Windows
- Baseado em camadas, onde cada camada cumpre uma função específica.

## Arquitetura

### Kernel
- Núcleo do sistema operacional, responsável por gerenciar os recursos do hardware, como processadores, memória e dispositivos de entrada e saída;
- Fornece uma interface entre os aplicativos e o hardware, garantindo que cada programa tenha acesso aos recursos necessários para funcionar corretamente;
- Também é responsável por gerenciar a segurança do sistema, controlando o acesso aos recursos e protegendo-os contra ameaças.

### Subsistemas
- O Windows possui diferentes subsistemas que permitem a execução de diferentes tipos de aplicativos:
	- O subsistema Win32 é responsável por executar aplicativos de 32 bits, enquanto o subsistema Win64 é usado para aplicativos de 64 bits;
	- O Windows também possui subsistemas para executar aplicativos baseados em console, como o CMD, e aplicativos baseados em interface gráfica, como o Windows Explorer.

### Serviços
- Programas que são executados em segundo plano e fornecem funcionalidades específicas para o sistema operacional e para os aplicativos.
- Alguns exemplos de serviços do Windows incluem o serviço de impressão, o serviço de rede e o serviço de segurança. Esses serviços são iniciados automaticamente quando o sistema é inicializado e executam tarefas essenciais para o funcionamento do sistema.
---------------
## Inicialização

- Durante a inicialização, é executada uma série de eventos e sequências que permitem o carregamento correto do sistema operacional;
- A sequência de inicialização do Windows começa com a inicialização do computador, seguida pelo POST (Power-On Self Test) que verifica o hardware do sistema. Em seguida, é carregado o bootloader, que é um programa localizado no setor de boot do disco rígido. Este bootloader carrega o kernel do sistema operacional e outros arquivos necessários para a inicialização;
- Durante o processo de inicialização, podem ser encontrados erros ou problemas que impedem a inicialização adequada. Para resolver esses problemas, é aconselhável usar opções de recuperação do Windows, como modo de segurança ou reparo automático.'

---------------
## Referências
- https://www.procedimento.com.br/?p=go&windows=a-arquitetura-do-sistema-operacional-windows-uma-viso-geral&os=windows
- https://tecnobits.com/pt/como-funciona-o-sistema-operacional-windows/
