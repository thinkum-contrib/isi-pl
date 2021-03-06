;; stella-stella.asd - ASDF interop for PowerLoom(r) STELLA        -*- lisp -*-

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


;; NB: This system definition should provide support for evaluating the
;; PL STELLA system in a manner beginning from evaluation of the STELLA
;; system definition provided in pl:sources;systems;stella-system.ste
;;
;; This may, albeit, result in a STELLA system somewhat differing to
;; that provided in Common Lisp source form, in the original, public
;; PowerLoom(r) distribution (FIXME QA) assuming that the Common Lisp
;; implementation produced from the STELLA source files for STELLA may
;; not exactly match -- in file form, at least -- the Common Lisp
;; implementation for STELLA provided in the original PowerLoom(r)
;; distribution, or that with updates provided in this
;; contrib. repository
;;
;; ----
;;
;; This system definition may be developed in parallel to the support
;; for ASDF interoperability insofar as concerning the STELLA system
;; definitions representing the principal kernel and interactive forms
;; of the PowerLoom environment i.e
;;   pl:sources;systems;logic-system.ste
;; and
;;   pl:sources;systems;powerloom-system.ste
;;
;; Such support may be provided to the user as, in effect, emulating
;; load-powerloom.lisp using the contributed PL ASDF systems.
;;
;; ----
;;
;; This assumes that the STELLA system has already been loaded into the
;; Common Lisp implementation - as vis a vis the ASDF system definition
;; stella-init.asd
;;


(in-package #:cl-user)

;; NB in lieu of a system definition lib, extensional to ASDF,
;; the following should result in stella-init.asd being evaluated
;; as a Lisp source file
(eval-when (:compile-toplevel :load-toplevel :execute)
  (asdf:find-system "stella-init")
  )

(in-package #:stella-system)

;; NB some stella-init.asd code may be reused in stella-stella.asd
