WHAT IS SHCF_LIB?

shcf_lib is a spin-off of the libraries of shcf so that it could live outside the confines of the shcf(http://ismael.casimpan.com/shcf) and grow in leaps and bounds hopefully.

shcf will be repurposed such that it will become a light shell scripting framework and be needed only on the creation of a complex script. A sort of "compile option" will be added to it so that the script will "come out of the shell" (meaning, run on it's own without using the shcf framework).

FORMAT

Directory format would initially be as follows:
  lib
    \-> [broad_category/sub_category_1/sub_category_n]
          \-> script_name_dir
		\-> script_name.bash.inc
		\-> script_name.utest.inc
		\-> script_name.deps.inc
		\-> script_name.readme.txt
 where:
  * script_name.bash.inc  - the function itself
  * script_name.utest.inc - the unit test of the function
  * script_name.deps.inc  - the dependencies of the function that will be in ini like format as follows:
 
 [BIN]
  wget
  curl
  sed
  ping

 [AUTOLOAD]
   db/nosql/ffdb/get_datarow

   * BIN will contain all the needed binaries of the function and will be written to shcf/etc/binaries.conf if it doesn't exist yet.
         Non-existing binary will cause library installer to fail (with easy to read instructions on how to fix it)
   * AUTOLOAD contains all the function dependencies and will be written to the path specified

Example for lib\db\nosql\get_specificdata.bash.inc, it would be:
  lib
    \-> db/nosql/ffdb/
          \-> get_specificdata
		\-> get_specificdata.bash.inc
		\-> get_specificdata.utest.inc
		\-> get_specificdata.deps.inc
		\-> get_specificdata.readme.txt

CURRENT STATUS:

Right now, there is no script yet that would make the above quick and easy. It has to be done manually until such time I manage to code those.
Or if you want to help, just send a pull request. I'll be happy to review and incorporate as needed.
