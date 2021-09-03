/*///////////////////////////////CRIA AS TABELAS E A BASE DE DADOS///////////////////////////////////////////////////*/

DROP TABLE test; 		/* deleta a tabela */
DROP DATABASE test;		/* deleta a base de dados(database) */

CREATE DATABASE record_company;		/* cria a base de dados */
USE record_company;					/* bota a base de dados em uso, alterações são feitas nela, enquanto selecionada */

CREATE TABLE bands(							/* cria tabela `bands` */
	id INT NOT NULL AUTO_INCREMENT,			/* cria coluna de numeros inteiros, sem nulos, que incrementa sozinho */
	name VARCHAR(255) NOT NULL ,			/* cria coluna de nomes tipo string não nulos até 255 chars */
    PRIMARY KEY (id)						/* torna id a coluna principal de identificação da tabela */
);

ALTER TABLE records		/* altera a tabela */
/* pode quebrar linha */
ADD music VARCHAR(255); /* adiciona algo a tabela existente */ 

CREATE TABLE Albums(
	id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(255),
    release_date INT,			 /* coluna de data de lançamento */
    band_id INT NOT NULL,		
    PRIMARY KEY (id),			/* cria outra chave primaria, nomes não interferem */
    
    FOREIGN KEY (band_id) REFERENCES bands (id) /* relaciona a coluna band_id com a id da tabela bands */
);
/*/////////////////////////////ADICIONA INFORMAÇÕES NAS TABELAS/////////////////////////////////////////////////////*/

INSERT INTO bands (name) VALUES ('Foo Fighters');		/* adiciona foo fighters na tabela, com valor 1 */ 
INSERT INTO bands (name) VALUES ('My Chemical Romance'), ('Black Sabbath'), ('Titãs'), ('Queen'); /* pode botar mais de uma vez */
INSERT INTO bands (name) VALUES ( 'Iron Maiden');

SELECT * FROM bands;			/* consulta todos os dados da tabela bands ( * significa todos) */
DELETE FROM bands WHERE id=1;	/* deleta os dados com a condição selecionada ( mantém a ordem dos ID) */
SELECT * FROM bands LIMIT 2;	/* seleciona e consulta uma quantidade limitada de dados */
SELECT name FROM bands;  		/* consulta uma coluna específica */

/*RENAME COLUMNS*/
SELECT id AS 'ID', name AS 'Band Name' FROM bands; /* (AS = alias= apelido)  muda o nome */ 
/*//////////////*/
SELECT * FROM bands ORDER BY name;		/* ordena por nome mas apenas ao usar esse comando, pois não é a key primaria*/
SELECT * FROM bands ORDER BY name DESC;	/* ordena de baixo pra cima	( DESCEND ), ASCEND(ASC é a forma normal é selecionada automaticamente */

INSERT INTO Albums (name, release_date, band_id)
VALUES 			   ('Power Slave',   1984,	  7),
				   ('Nightmare'	, 2018, 6),
                   ('Teste', NULL, 5), ('Album teste', 10, 5);
SELECT * FROM Albums;
SELECT DISTINCT names FROM Albums;		/* consulta apenas nomes não repetidos, DISTINCT compara os nomes e apenas mostra um dos iguais*/

/*/////////////////////////////////MUDAR DADOS JÁ ADICIONADOS/////////////////////////////////////////*/
UPDATE Albums 		
SET release_date = 1982 WHERE id  = 4;			/* atualiza os dados com id 4*/ 
/*///////////*/
SELECT * FROM Albums WHERE release_date > 2000;		/* mostra dados após os anos 2000*/
SELECT * FROM Albums WHERE name LIKE '%er%';		/* mostra todos os dados similares que contenham 'er' em alguma parte do nome*/ 
SELECT * FROM Albums WHERE name LIKE '%er%' OR band_id=2; /*     ||      */
SELECT * FROM Albums WHERE name LIKE '%er%' AND band_id=1;/*     &&      */
SELECT * FROM Albums WHERE release_date BETWEEN 1950 AND 2020; 	/* entre, BETWEEN*/
SELECT * FROM Albums WHERE release_date IS NULL;

DELETE FROM Albums WHERE id = 3;		/* deleta album de id 3 */

SELECT * FROM bands 						/*mostra apenas as bandas que tem albums e seus respectivos albums*/
JOIN Albums ON bands.id = Albums.band_id;	/*compara e junta as tabelas em uma só*/


