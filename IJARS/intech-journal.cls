%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%														
%%%		LaTeX .cls for InTech Journal Articles
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Developed and maintained by PanType d.o.o.
%%%		www.pantype.com, info@pantype.com
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Main
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\NeedsTeXFormat{LaTeX2e}[1995/12/01]
\ProvidesClass{intech-journal}[2012/10/01]

\ProcessOptions \relax
\typeout{**************************************************************************}
\typeout{*** For any technical support contact: 								***}
\typeout{*** randjelovic@pantype.com or sijan@intechopen.com					***}
\typeout{**************************************************************************}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Packages and page setup
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\LoadClass[twoside,twocolumn]{article}

\RequirePackage{ifthen}
\RequirePackage[papersize={21cm,29.7cm},top={2.9cm},bottom={2.5cm},left={2cm},right={2cm},headsep={1.27cm},dvips,pdftex]{geometry}
\RequirePackage{amsfonts,amstext,amssymb,amsmath,amsthm,amscd,bm,paralist,color}
\RequirePackage{graphicx,array}
\RequirePackage{epstopdf}
\RequirePackage{mathpazo}
\RequirePackage{courier}
\RequirePackage[T1]{fontenc}
\RequirePackage{textcomp}
\RequirePackage[sort&compress]{natbib}
\RequirePackage[english]{babel}
\RequirePackage[singlelinecheck=false,labelsep=period,skip=9pt,justification=justified,font={small},labelfont={bf}]{caption}
\captionsetup{figurename=Figure}
\RequirePackage{subfigure}
\RequirePackage[bottom]{footmisc}
\RequirePackage{float,verbatim}
\RequirePackage{dblfloatfix}
\RequirePackage{fancyhdr}
\RequirePackage{calc}
\RequirePackage{titlesec}
\RequirePackage[none]{hyphenat}
\RequirePackage{setspace}
\RequirePackage[breaklinks,hyperfootnotes=false,colorlinks=true,linkcolor=black,urlcolor=black,citecolor=black,filecolor=black]{hyperref}
\urlstyle{same}
\RequirePackage[noblocks]{authblk}
\RequirePackage{lastpage}
\RequirePackage[runin]{abstract}
%\RequirePackage[section]{placeins}
%\RequirePackage{multicol}

\raggedbottom
\addtolength{\topskip}{0pt plus 12pt}
\setlength{\parindent}{0pt}
\setlength{\parskip}{6pt plus 0.5ex minus 0.2ex}
\definecolor{intech_blue}{cmyk}{1,0.35,0,0.44}  
\definecolor{intech_darkblue}{cmyk}{0.94,0.37,0,0.46} % www.intechopen.com & logos
\definecolor{grey_line}{cmyk}{0.03,0,0.01,0.56}  % titlepage lines
\renewcommand\Authfont{\Large\fontfamily{fvs}\selectfont}
\renewcommand\Affilfont{\small\fontfamily{fvs}\selectfont\color{grey_line}}
\renewcommand\Authands{ and }
\setlength{\affilsep}{9pt}
\setlength{\abstitleskip}{-\parindent} 
\setlength{\absleftindent}{0pt} 
\setlength{\absrightindent}{0pt}
\renewcommand{\abstractnamefont}{\normalsize\textcolor{intech_blue}}
\renewcommand{\abstracttextfont}{\normalsize}
\newcommand{\keywords}[1]{\par\noindent{\normalsize{\normalsize\textcolor{intech_blue}{Keywords\/}} #1}} % if there is a dot at the end (., ! or ?) do nothing, otherwise add . -> \ifnum\the\spacefactor>3000. \fi
\newcommand{\articleabstract}[1]{\begin{abstract}\label{abstract} #1\end{abstract}}
\renewcommand{\captionfont}{\footnotesize\fontfamily{fvs}\selectfont}
\renewcommand{\captionlabelfont}{\bfseries\footnotesize\fontfamily{fvs}\selectfont}
\captionsetup[table]{justification=raggedright,position=bottom}

\setlength{\columnsep}{0.75cm}
\setlength{\unitlength}{1mm}

\pagestyle{fancy}
  \fancyhf{} %clears previuos settings
  \fancyfoot[LE]{
		\begin{picture}(0,0)
		\put(-4.7,0) {\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\thepage}}
		\end{picture}}
  \fancyfoot[RO]{
		\begin{picture}(0,0)
		\put(4.7,0) {\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\thepage}}
		\end{picture}}
  \fancyfoot[RE]{{\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\shortjournaltitle\ \@pubyear, Vol. \@volume, \@articlenumber:\@pubyear}} % pages range \pageref*{abstract}--\pageref*{LastPage}
  \hfill{}{\footnotesize\fontfamily{fvs}\selectfont\textcolor{intech_darkblue}{www.intechopen.com}}}
  \fancyfoot[LO]{{\footnotesize\fontfamily{fvs}\selectfont\textcolor{intech_darkblue}{www.intechopen.com}}\hfill{}{\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\phantom{\@authorlist} :}} \\[-2pt]
  {{ }\hfill{}{\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\runningtitle}}}}
  \renewcommand{\headrulewidth}{0pt}%
  \cfoot{}

\widowpenalty=9999
\clubpenalty=9999

\newlength{\myFootnoteWidth}
\newlength{\myFootnoteLabel}
\setlength{\myFootnoteLabel}{0.8em}
\renewcommand{\@makefntext}[1]{%
  \setlength{\myFootnoteWidth}{\columnwidth}%
  \addtolength{\myFootnoteWidth}{-\myFootnoteLabel}%
  \noindent\makebox[\myFootnoteLabel][r]{\@makefnmark\ }%
  \parbox[t]{\myFootnoteWidth}{#1}%
}

%
% multicol option, obsolete
%
%\def\closeopenmulticols{
%   \def\@tempa{multicols}
%   \ifx\@tempa\@currenvir
%      \end{multicols}
%  \fi 
%}
%
%\AtEndDocument{\closeopenmulticols}
%
%\newcommand{\wide}[1]{\closeopenmulticols#1\begin{multicols}{2}}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Title page
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\newcommand{\articletitle}[1]{\gdef\@articletitle{#1}}
\newcommand{\@articletitle}{\@latex@error{No \noexpand\articletitle given}\@ehc}

\newcommand{\runningtitle}{\let\\=\relax\@articletitle}

\newcommand{\correspemail}[1]{\gdef\@correspemail{#1}}
\newcommand{\@correspemail}{\@latex@error{No \noexpand\correspemail given}\@ehc}

\newcommand{\journaltitle}[1]{\gdef\@journaltitle{#1}}

\newcommand{\shortjournaltitle}{%
		\ifthenelse{\equal{\@journaltitle}{International Journal of Advanced Robotic Systems}}{Int J Adv Robotic Sy,}{}%
		\ifthenelse{\equal{\@journaltitle}{Nanomaterials and Nanotechnology}}{Nanomater Nanotechnol,}{}%
		\ifthenelse{\equal{\@journaltitle}{International Journal of Engineering Business Management}}{Int J Eng Bus Manag,}{}%
		\ifthenelse{\equal{\@journaltitle}{International Journal of Radio Frequency Identification \& Wireless Sensor Networks}}{Int J Radio Freq Identify Wirel Sens Netw,}{}%
		\ifthenelse{\equal{\@journaltitle}{International Journal of Agricultural Chemistry}}{Int J Agr Chem,}{}%
		\ifthenelse{\equal{\@journaltitle}{International Journal of Regenerative Medicine}}{Int J Reg Med,}{}%
		\ifthenelse{\equal{\@journaltitle}{International Food Risk Analysis Journal}}{Int Food Risk Anal J,}{}%
		\ifthenelse{\equal{\@journaltitle}{Journal Name}}{Short Journal Name,}{}%
		\ifthenelse{\equal{\@journaltitle}{}}{unknown}{}%
		}

\newcommand{\volume}[1]{\gdef\@volume{#1}}
\newcommand{\@volume}{\@latex@error{No \noexpand\volume given}\@ehc}

\newcommand{\pubyear}[1]{\gdef\@pubyear{#1}}
\newcommand{\@pubyear}{\@latex@error{No \noexpand\pubyear given}\@ehc}

\newcommand{\licensee}[1]{\gdef\@licensee{#1}}
\newcommand{\@licensee}{\@latex@error{No \noexpand\licensee given}\@ehc}

\newcommand{\authorlist}[1]{\gdef\@authorlist{#1}}
\newcommand{\@authorlist}{\@latex@error{No \noexpand\authorlist given}\@ehc}

\newcommand{\dates}[2][]{\gdef\@dates{\ifthenelse{\equal{#1}{}}{Accepted #2 \@pubyear}{Received #1 \@pubyear; Accepted #2 \@pubyear}}}

\newcommand{\doi}[1]{\gdef\@doi{DOI: 10.5772/#1}}
\newcommand{\@doi}{\@latex@error{No \noexpand\doi given}\@ehc}

\newcommand{\articlenumber}[1]{\gdef\@articlenumber{#1}}
\newcommand{\@articlenumber}{\@latex@error{No \noexpand\articlenumber given}\@ehc}

\newcommand{\articletype}[1]{\ifthenelse{\equal{#1}{inv}}{\gdef\@articletype{Invited Paper}}{\gdef\@articletype{Regular Paper}}}
\newcommand{\@articletype}{}

\newcommand{\corresp}{$^\star$}

% defaults 
\licensee{\phantom{FIRST AUTHOR}}
\correspemail{\phantom{EMAIL}}
\journaltitle{Journal Name}
\volume{No}
\pubyear{2013}
\authorlist{\phantom{AUTHOR LIST}}
\doi{chapter.doi}
\articlenumber{No}
\articletype{}
\dates[D M]{D M}


\setlength{\unitlength}{1mm}
\fancypagestyle{plain}{%
  \fancyhf{} 
  \fancyhead[L]{
		\begin{picture}(23,14)
		\includegraphics{InTech_logo.eps}  
		\end{picture}
		}
  \fancyhead[R]{
		\begin{picture}(33,16)
		\includegraphics{OpenAccess_logo.eps} 
		\end{picture}
		}
  \fancyfoot[R]{
		\begin{picture}(0,0)
		\put(4.7,0) {\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\thepage}}
		\end{picture}}
  \fancyfoot[L]{{\footnotesize\fontfamily{fvs}\selectfont\textcolor{intech_darkblue}{www.intechopen.com}}\hfill{}
		{\footnotesize\fontfamily{fvs}\selectfont\textcolor{grey_line}{\shortjournaltitle\ \@pubyear, Vol. \@volume, \@articlenumber:\@pubyear}}}  % pages range \pageref*{abstract}--\pageref*{LastPage}
  \renewcommand{\headrulewidth}{0pt}%
  \renewcommand{\footrulewidth}{0pt}%
}

\def\@maketitle{\newpage
\setlength{\parsep}{0pt plus 0.5ex minus 0.2ex}
\begin{flushleft}
{\Large\fontfamily{fvs}\selectfont\@journaltitle}\\[70pt]
\begin{spacing}{1.6}{\Huge\fontfamily{fvs}\selectfont\textcolor{intech_blue}{\@articletitle}}\vspace{12pt}\end{spacing}
{\Large\fontfamily{fvs}\selectfont{\@articletype}}\\[11pt]
\rule{22mm}{.5pt}\\[19pt]
%{\@author}\\
{\small\fontfamily{fvs}\selectfont{$^\star$ Corresponding author E-mail: \@correspemail}}\\[9pt]
{\small\fontfamily{fvs}\selectfont\textcolor{grey_line}{\ifthenelse{\equal{\@articletype}{Invited Paper}}{\@dates}{\@dates}}}\\[6pt] % if loop is for different \dates definition (in accordance with \articletype def)
{\small\fontfamily{fvs}\selectfont{\@doi}}\\[6pt]
\begin{spacing}{0.8}{\small\fontfamily{fvs}\selectfont{\copyright\ \@pubyear\ \phantom{\@licensee}; licensee InTech. This is an open access article distributed under the terms of the Creative Commons Attribution License (\url{http://creativecommons.org/licenses/by/3.0}), 
which permits unrestricted use, distribution, and reproduction in any medium, provided the original work is properly cited.}}\vspace{15pt}\end{spacing}
\rule{22mm}{2pt}\\[10pt]
\end{flushleft}
}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Journal structure and fonts
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\def\@sect#1#2#3#4#5#6[#7]#8{%
  \ifnum #2>\c@secnumdepth
    \let\@svsec\@empty
  \else
    \refstepcounter{#1}%
    \protected@edef\@svsec{\csname the#1\endcsname
\ifnum #2<1.\fi}%
  \fi
  \@tempskipa #5\relax
  \ifdim \@tempskipa>\z@
    \begingroup
      #6{%
        \@hangfrom{\hskip #3\relax\@svsec\hspace{1ex}}%
          \interlinepenalty \@M #8 \@@par}%
    \endgroup
    \csname #1mark\endcsname{#7}%
    \addcontentsline{toc}{#1}{%
      \ifnum #2>\c@secnumdepth \else
        \protect\numberline{\csname the#1\endcsname}%
      \fi
      #7}%
  \else
    \def\@svsechd{%
      #6{\hskip #3\relax
      \@svsec #8}%
      \csname #1mark\endcsname{#7}%
      \addcontentsline{toc}{#1}{%
        \ifnum #2>\c@secnumdepth \else
          \protect\numberline{\csname the#1\endcsname}%
        \fi
        #7}}%
  \fi
  \@xsect{#5}}

\renewcommand\normalsize{%
   \@setfontsize\normalsize\@ixpt{11}%
   \abovedisplayskip 8.5\p@ \@plus3\p@ \@minus4\p@
   \abovedisplayshortskip \z@ \@plus2\p@
   \belowdisplayshortskip 4\p@ \@plus2\p@ \@minus2\p@
   \def\@listi{\leftmargin\leftmargini
               \topsep 4\p@ \@plus2\p@ \@minus2\p@
               \parsep 2\p@ \@plus\p@ \@minus\p@
               \itemsep \parsep}%
   \belowdisplayskip \abovedisplayskip
}
\renewcommand \small{%
   \@setfontsize \small\@viiipt{9.5}%
   \abovedisplayskip 6\p@ \@plus2\p@ \@minus4\p@
   \abovedisplayshortskip \z@ \@plus\p@
   \belowdisplayshortskip 3\p@ \@plus\p@ \@minus2\p@
   \def\@listi{\leftmargin\leftmargini
               \topsep 3\p@ \@plus\p@ \@minus\p@
               \parsep 2\p@ \@plus\p@ \@minus\p@
               \itemsep \parsep}%
  \belowdisplayskip \abovedisplayskip
}

\renewcommand\scriptsize{\@setfontsize\scriptsize\@viiipt\@ixpt}
\renewcommand\tiny{\@setfontsize\tiny\@vpt\@vipt}
\renewcommand\large{\@setfontsize\large\@xpt\@xiipt}
\renewcommand\Large{\@setfontsize\Large\@xiipt{13.6}}
\renewcommand\LARGE{\@setfontsize\LARGE{15.3}{20.6}}
\renewcommand\huge{\@setfontsize\huge{18}{23}}
\renewcommand\Huge{\@setfontsize\Huge{27}{30}}
\renewcommand\small{\@setfontsize\small{8}{9.5}}
\renewcommand\footnotesize{\@setfontsize\footnotesize{7}{8.5}}

\setcounter{secnumdepth}{5}%
\setcounter{tocdepth}{5}%

\titleformat{\section}[block]{\normalfont\normalsize\raggedright}{\textcolor{intech_blue}{\thesection.}}{.2em}{\normalfont\normalsize\textcolor{intech_blue}}[\rm]
\titleformat{\subsection}[block]{\itshape\normalsize\raggedright}{\thesubsection.}{.2em}{\itshape\normalsize}[\rm]
\titleformat{\subsubsection}[block]{\itshape\normalsize\raggedright}{\thesubsubsection.}{.2em}{\itshape\normalsize}[\rm]
\titleformat{\paragraph}[block]{\itshape\normalsize\raggedright}{\theparagraph}{.2em}{\itshape\normalsize}[\rm]
\titleformat{\subparagraph}[block]{\itshape\normalsize\raggedright}{\thesubparagraph}{.2em}{\itshape\normalsize}[\rm]

\titlespacing{\section}{0pt}{8pt}{0pt}
\titlespacing{\subsection}{0pt}{8pt}{0pt}
\titlespacing{\subsubsection}{0pt}{8pt}{0pt}
\titlespacing{\paragraph}{0pt}{0pt}{0pt}
\titlespacing{\subparagraph}{0pt}{0pt}{0pt}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Floats
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\setlength\parindent{15em}
\setcounter{topnumber}{8}
\renewcommand\topfraction{1}
\setcounter{bottomnumber}{3}
\renewcommand\bottomfraction{.99}
\setcounter{totalnumber}{8}
\renewcommand\textfraction{0.01}
\renewcommand\floatpagefraction{.8}
\setcounter{dbltopnumber}{6}
\renewcommand\dbltopfraction{1}
\renewcommand\dblfloatpagefraction{.8}

\setlength\floatsep        {6\p@ \@plus 2\p@ \@minus 2\p@}
\setlength\textfloatsep   {6\p@ \@plus 2\p@ \@minus 2\p@}
\setlength\intextsep      {12\p@ \@plus 2\p@ \@minus 2\p@}
\setlength\dblfloatsep    {6\p@ \@plus 2\p@ \@minus 2\p@}
\setlength\dbltextfloatsep{6\p@ \@plus 2\p@ \@minus 2\p@}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Lists
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\setlength{\parindent}{13pt}
\newdimen\svitemindent \setlength{\svitemindent}{\parindent}

\def\setitemindent#1{\settowidth{\labelwidth}{#1}%
        \let\setit@m=Y%
        \leftmargini\labelwidth
        \advance\leftmargini\labelsep
   \def\@listi{\leftmargin\leftmargini
        \labelwidth\leftmargini\advance\labelwidth by -\labelsep
        \parsep=\parskip
        \topsep=\medskipamount
        \itemsep=\parskip \advance\itemsep by -\parsep}}
\def\setitemitemindent#1{\settowidth{\labelwidth}{#1}%
        \let\setit@m=Y%
        \leftmarginii\labelwidth
        \advance\leftmarginii\labelsep
\def\@listii{\leftmargin\leftmarginii
        \labelwidth\leftmarginii\advance\labelwidth by -\labelsep
        \parsep=\parskip
        \topsep=\z@
        \itemsep=\parskip \advance\itemsep by -\parsep}}

\def\itemize{%
  \ifnum \@itemdepth >\thr@@\@toodeep\else
    \advance\@itemdepth\@ne
    \ifx\setit@m\undefined
       \ifnum \@itemdepth=1 \leftmargini=\svitemindent
          \labelwidth\leftmargini\advance\labelwidth-\labelsep
          \leftmarginii=\leftmargini \leftmarginiii=\leftmargini
       \fi
    \fi
    \edef\@itemitem{labelitem\romannumeral\the\@itemdepth}%
    \expandafter\list
      \csname\@itemitem\endcsname
      {\def\makelabel##1{\rlap{##1}\hss}}%
  \fi}

\let\ts\,

\setlength \labelsep     {5\p@}
\setlength\leftmargini   {13\p@}
\setlength\leftmargin    {\leftmargini}
\setlength\leftmarginii  {\leftmargini}
\setlength\leftmarginiii {\leftmargini}
\setlength\leftmarginiv  {\leftmargini}
\setlength\labelwidth    {\leftmargini}
\addtolength\labelwidth{-\labelsep}

\def\@listI{\leftmargin\leftmargini
        \parsep=\parskip
        \topsep=\medskipamount
        \itemsep=\parskip \advance\itemsep by -\parsep}
\let\@listi\@listI
\@listi

\def\@listii{\leftmargin\leftmarginii
        \labelwidth\leftmarginii
        \advance\labelwidth by -\labelsep
        \parsep=\parskip
        \topsep=\z@
        \itemsep=\parskip
        \advance\itemsep by -\parsep}

\def\@listiii{\leftmargin\leftmarginiii
        \labelwidth\leftmarginiii\advance\labelwidth by -\labelsep
        \parsep=\parskip
        \topsep=\z@
        \itemsep=\parskip
        \advance\itemsep by -\parsep
        \partopsep=\topsep}

\setlength\arraycolsep{1.5\p@}
\setlength\tabcolsep{1.5\p@}

\renewcommand{\labelitemii}{\textbullet}

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		Resetup and misc.
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

\renewcommand\footnoterule{%
  \kern-3\p@
  \hrule\@width 50\p@
  \kern2.6\p@}

\newdimen\foot@parindent
\foot@parindent 10.83\p@

\renewcommand{\bibsection}{\section{References}}
\setlength{\bibhang}{1.24cm}
\setlength{\parindent}{3cm}
\setlength{\bibsep}{0cm}
\bibliographystyle{unsrt}
\gdef\harvardand{\&}
\renewcommand\harvardurl[1]{\textnormal{URL:} \textit{#1}}

\usepackage{soul}% razmak izmedju slova
\sodef\rzs{\normalfont}{-.03em}{.1em }{3.1em}

\setlength{\parindent}{0pt}
\sloppypar 

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% 													
%%%		EOF
%%%														
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
