(defproject clover "0.1.0-SNAPSHOT"
  :description "FIXME: write description"
  :url "http://example.com/FIXME"
  :license {:name "Eclipse Public License"
            :url "http://www.eclipse.org/legal/epl-v10.html"}
  :dependencies [[org.clojure/clojure "1.9.0"]
                 [org.clojure/tools.analyzer "0.6.9"]
                 [com.bhauman/rebel-readline "0.1.4"]]
  :main ^:skip-aot clover.core
  :target-path "target/%s"
  :profiles
  {
   :uberjar {:aot :all
             :jvm-opts ["-Dclojure.compiler.direct-linking=true"]}}
  :repl {:plugins [[cider/cider-nrepl "0.18.0"]]})
