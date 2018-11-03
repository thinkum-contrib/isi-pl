Thinkum Labs Contrib for ISI PowerLoom(R)
=========================================

# Overview

This source tree represents a fork of [PowerLoom(R)][pl]. [PowerLoom(R)][pl] is a
free/open source software (FOSS) project developed originally at the
[Information Sciences Institute][isi] (ISI) of the
[University of Southern California][usc] (USC).

This fork is developed independent of the original [PowerLoom(R)][pl]
project.

# Components

The version 4 releases of [PowerLoom(R)][pl] are distribued with
software components including:

* The [STELLA Programming Language][stella] - functional language, with
  source code synthesis for implementation of the PowerLoom(R) Knowledge
  Representation System (KRS) in Common Lisp, C++, and Java(R)
  programming languages

* PowerLoom(R) System Support Components, such as for the PowerLoom(R)
  server, RDBMS services for PowerLoom(R), and Ontosaurus

* Example Knowledgebases

* Documentation


# Existing Works

* PowerLoom(R)
* OKBC
* Loom(R)
* KL-ONE


# Repository Structure

This source repository contains the following Git branches. Each of
these branches was created from an original PowerLoom(R) source release,
as distributed in Gzipped Tape Archive format [[availability][pldl]]

* `powerloom-1.0.alpha`
* `powerloom-2.0.0.alpha`
* `powerloom-3.0.1.beta`
* `powerloom-3.0.2.beta`
* `powerloom-3.2.0`
* `powerloom-4.0.0.beta`
* `powerloom-4.0.4.beta`
* `powerloom-4.0.5.beta`
* `powerloom-4.0.6.beta`
* `powerloom-4.0.7.beta`
* `powerloom-4.0.8.beta`
* `powerloom-4.0.9.beta`
* `powerloom-4.0.10`

The branch, `contrib_main`, represents a _contribution branch_ onto the
_release branch_, `powerloom-4.0.10`.

# Licensing

Quoting the page, _[Download PowerLoom][pldl]_ (December 2015)

> Since 2005, PowerLoom(R) is available free-of-charge under a triple
> disjunctive open-source licensing scheme that allows you to pick the
> Mozilla Public License v. 1.1 (MPL), the GNU General Public License
> v. 2.0 (GPL) or the the GNU Lesser Public License v. 2.1 (LGPL) to
> fit your needs. This scheme is similar to what's used for the
> Mozilla web browser and should give people maximum flexibility to
> use PowerLoom even for commercial development while still retaining
> the advantages of open-source licensing.

Except where denoted otherwise, this fork retains those licensing
stipulations for all files contributed within this source repository.

# Further Documentation

**Documentation in This Repository**

* `README-POWERLOOM`
* `README-STELLA`
* `sources/stella/README` - STELLA Installation Guide
* `sources/stella/doc/`
    * `sources/stella/doc/manual.pdf`
* `sources/logic/README` - PowerLoom(R) Installation Guide
* `sources/logic/doc/PowerLoom-Overview-Slides.ppt`
* `sources/powerloom/doc/`
    * `sources/powerloom/doc/manual.pdf` - PowerLoom(R) Manual
* `native/cpp/stella/cpp-lib/gc/doc/`
* `sources/powerloom-gui/src/overview.html`
* `htdocs/ontosaurus/help/`
* `sources/powerloom-server/plsoap/README`
* `sources/webtools/tomcat/README`

**Documentation on the Web**

* [PowerLoom(R) Knowledge Representation and Reasoning System][pl] -
  [ISI][isi] at [USC][usc]

# Notification - Marks of Trade

Loom and PowerLoom are registered trademarks of the University of
Southern California.

[pl]: http://www.isi.edu/isd/LOOM/PowerLoom/
[usc]: http://www.usc.edu/
[isi]: http://www.isi.edu/
[stella]: http://www.isi.edu/isd/LOOM/Stella/index.html
[pldl]: http://www.isi.edu/isd/LOOM/PowerLoom/download.html
[asdf]: https://common-lisp.net/project/asdf/
[usocket]: https://github.com/usocket/usocket
[bthread]: https://gitlab.common-lisp.net/bordeaux-threads/bordeaux-threads
