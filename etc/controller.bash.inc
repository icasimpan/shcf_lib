## =================================================================================================================
## FILENAME: controller.bash.inc
## PURPOSE : controller (mediator) script between the models(individual functions) and view(each individual scripts)
## =================================================================================================================

TOOL_ROOTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )"/../ && pwd )"
LIB_DIR=$TOOL_ROOTDIR/lib
CONF_DIR=$TOOL_ROOTDIR/etc

. $CONF_DIR/init.conf
. $LIB_DIR/autoload_functions.bash.inc

## in each utility script, this controller should be  sourced + functions to autoload as follows:
## ----------------- START: autoloading -----------------------
## . $HOME/etc/controller.bash.inc
##
## functions_to_autoload="
## function1
## function2
## function_n
## "
## autoload_functions "$functions_to_autoload"
## ----------------- END: autoloading -----------------------

