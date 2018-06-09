
TEMPLATE = subdirs

SUBDIRS = \
        base \
        control \
        complex \
        data

complex.depends = base
control.depends = base
data.depends = base control


DISTFILES += \
    models/alternative_execute.plantuml \
    models/alternative_isRightToLeft.plantuml \
    models/assign_execute.plantuml \
    models/assign_isExecutable.plantuml \
    models/class_diagram.plantuml \
    models/context_containsData.plantuml \
    models/context_endContext.plantuml \
    models/context_execute.plantuml \
    models/context_isExecutable.plantuml \
    models/context_isRightToLeft.plantuml \
    models/context_newContext.plantuml \
    models/context_startContext.plantuml \
    models/else_isExecutable.plantuml \
    models/function_isExecutable.plantuml \
    models/if_execute.plantuml \
    models/method_execute.plantuml \
    models/object_containsData.plantuml \
    models/property_execute.plantuml \
    models/uml_style.iuml \
    models/context_order_table.odt \
    models/alternative_checkPrev.plantuml \
    models/argument_checkPrev.plantuml \
    models/assign_checkPrev.plantuml \
    models/call_checkPrev.plantuml \
    models/code_checkPrev.plantuml \
    models/context_checkPrev.plantuml \
    models/context_isResultative.plantuml \
    models/else_checkPrev.plantuml \
    models/handler_checkPrev.plantuml \
    models/if_checkPrev.plantuml \
    models/isolated_checkPrev.plantuml \
    models/method_checkprev.plantuml \
    models/new_checkPrev.plantuml \
    models/object_checkPrev.plantuml \
    models/property_checkPrev.plantuml \
    models/try_checkPrev.plantuml \
    models/if_isExecutable.plantuml \
    models/try_execute.plantuml \
    models/try_isExecutable.plantuml \
    models/handler_isExecutable.plantuml \
    models/code_execute.plantuml \
    models/code_isExecutable.plantuml \
    models/control_isExecutable.plantuml \
    models/control_isRightToLeft.plantuml \
    models/data_isExecutable.plantuml \
    models/call_execute.plantuml \
    models/new_execute.plantuml \
    models/commom_isExecutable.plantuml \
    models/commom_isRightToLeft.plantum
