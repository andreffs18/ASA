#Análise e Síntese de Algoritmos | 1º Relatório
Project assignments for the Analysis and Synthesis of Algorithms course for #2 Semester of LEIC, IST@Alameda

Grupo 162 | Francisco Baio (ist17****) e André Silva (ist175455)

##Introdução

Hey! I'm your first Markdown document in **StackEdit**[^stackedit]. Don't delete me, I'm very helpful! I can be recovered anyway in the **Utils** tab of the <i class="icon-cog"></i> **Settings** dialog.

```
// Foo
var bar = 0;
```



##Solução

> **Tip:** Check out the [<i class="icon-upload"></i> Publish a document](#publish-a-document) section for a description of the different output formats.

##Análise Teorica

**Markdown Extra** has a special syntax for tables:

Item     | Value
-------- | ---
Computer | $1600
Phone    | $12
Pipe     | $1

You can specify column alignment with one or two colons:

| Item     | Value | Qty   |
| :------- | ----: | :---: |
| Computer | $1600 |  5    |
| Phone    | $12   |  12   |
| Pipe     | $1    |  234  |


##Avaliação Experimental


You can render *LaTeX* mathematical expressions using **MathJax**, as on [math.stackexchange.com][1]:

The *Gamma function* satisfying $\Gamma(n) = (n-1)!\quad\forall n\in\mathbb N$ is via the Euler integral

$$
\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
$$

> **Tip:** To make sure mathematical expressions are rendered properly on your website, include **MathJax** into your template:

```
<script type="text/javascript" src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML"></script>
```

> **Note:** You can find more information about **LaTeX** mathematical expressions [here][4].


##Table of contents

You can insert a table of contents using the marker `[TOC]`:

[TOC]

##Function to run tests. by [@nuno-silva]
```sh
$ function test { ./main < tests/$1.in > tests/$1.myout; diff tests/$1.myout tests/$1.out; }
$ function run_tests { for f in {01..05}; do test 0$f; done }
```


just run_tests
yey




[@nuno-silva]:https://github.com/nuno-silva
