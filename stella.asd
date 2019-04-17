;; stella.asd - Extending ASDF onto PowerLOOM(r), STELLA runtime   -*- lisp -*-


;;;;;;;;;;;;;;;;;;;;;;;;;;;;; BEGIN LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;                                                                            ;
;; Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          ;
;;                                                                            ;
;; The contents of this file are subject to the Mozilla Public License        ;
;; Version 1.1 (the "License"); you may not use this file except in           ;
;; compliance with the License. You may obtain a copy of the License at       ;
;; http://www.mozilla.org/MPL/                                                ;
;;                                                                            ;
;; Software distributed under the License is distributed on an "AS IS" basis, ;
;; WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   ;
;; for the specific language governing rights and limitations under the       ;
;; License.                                                                   ;
;;                                                                            ;
;; The Original Code is this system definition                                ;
;;                                                                            ;
;; The Initial Developer of the Original Code is                              ;
;;  Sean Champ spchamp@users.noreply.github.com                               ;
;; with some code excerpted from original developments by USC ISI, i.e        ;
;;  UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE         ;
;;  4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.              ;
;;                                                                            ;
;; Portions created by the Initial Developer are Copyright (C) 2015-2019      ;
;; the Initial Developer. All Rights Reserved.                                ;
;;                                                                            ;
;; Portions created by USC ISI are Copyright (C) 1996-2006                    ;
;; USC ISI. All Rights Reserved.                                              ;
;;                                                                            ;
;; Alternatively, the contents of this file may be used under the terms of    ;
;; either the GNU General Public License Version 2 or later (the "GPL"), or   ;
;; the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   ;
;; in which case the provisions of the GPL or the LGPL are applicable instead ;
;; of those above. If you wish to allow use of your version of this file only ;
;; under the terms of either the GPL or the LGPL, and not to allow others to  ;
;; use your version of this file under the terms of the MPL, indicate your    ;
;; decision by deleting the provisions above and replace them with the notice ;
;; and other provisions required by the GPL or the LGPL. If you do not delete ;
;; the provisions above, a recipient may use your version of this file under  ;
;; the terms of any one of the MPL, the GPL or the LGPL.                      ;
;;                                                                            ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; END LICENSE BLOCK ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(in-package #:cl-user)

;; NB PL impl source files
;;   native/lisp/powerloom/powerloom.lisp
;;   native/lisp/powerloom/startup-system.lisp
;;   and native/lisp/logic/*.lisp
;; subsq #'stella::powerloom (??)
;; or (stella::startup-powerloom-system)
;; and (in-module "STELLA") by default
;; cf. load-powerloom.lisp
;;
;; or (TBD side effects)
;; (stella::make-system "powerloom")
;; .. which needs an implementation of
;;    CL-USER::STELLA-NEED-TO-COMPILE? [Function]
;;    or a broader port/patch for PL-ASDF [FIXME]
;;
;; see also
;; - sources/systems/logic-system.ste
;;   and correspondingly sources/logic/*.ste
;;   - as towards native/lisp/logic/*.lisp
;;   - NB :lisp-only-files ("loom-api.lisp")
;; - sources/systems/powerloom.ste
;; * note that *.ste files can be evaluated, subsq of stella-init
;;   - see also: stella.asd
;;
;; Concept: Constructing an ASDF sysdef for a STELLA system for which,
;;   Common Lisp implementation source code has already been produced.
;;
;; TBD subsq. concept: Producing an ASDF sysdef and implementation
;;   source files, using an extension to ASDF and PL STELLA

;; NB: load-logic.lisp not avl - refer to logic-system.ste for
;; information about corresponding STELLA (ste) and implememtation
;; (lisp, slisp, C++, Java) source filea.

;; TBD: ordering of language-specific source files onto each STELLA
;; system :files list
;;
;;   - Note, stella-system.ste overlays some :lisp-only-files within the
;;     system's :files list. (Those that are not listed e.g in
;;     make-stella.lisp may be loaded otherwise within the original
;;     load-stella.lisp process flow.) This system definition may be
;;     unique, as such. (TBD: Testing STELLA source synthesis with STELLA
;;     init in each of C++, Java, IDL)
