#include "owl/deduce_types.hpp"

#include "owl/model.hpp"
#include "owl/visitor.hpp"

#include <iostream>

namespace owl {

struct deduce_ctx {
    //
};

static mod_node *visit_function(const visitor *v, deduce_ctx *dt_ctx, mod_function *e)
{
    std::cout << "visit function " << e->name << "\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_variable(const visitor *v, deduce_ctx *dt_ctx, mod_variable *e)
{
    std::cout << "visit variable " << e->name << "\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_object(const visitor *v, deduce_ctx *dt_ctx, mod_object *e)
{
    std::cout << "visit object " << e->name << "\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_struct(const visitor *v, deduce_ctx *dt_ctx, mod_struct *e)
{
    std::cout << "visit struct " << e->name << "\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_type(const visitor *v, deduce_ctx *dt_ctx, mod_type *e)
{
    std::cout << "visit type " << e->name << "\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_body(const visitor *v, deduce_ctx *dt_ctx, mod_body *e)
{
    std::cout << "visit body\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_stmt_return(const visitor *v, deduce_ctx *dt_ctx, mod_stmt_return *e)
{
    std::cout << "visit stmt return\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_expr_apply(const visitor *v, deduce_ctx *dt_ctx, mod_expr_apply *e)
{
    std::cout << "visit expr apply\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_expr_value(const visitor *v, deduce_ctx *dt_ctx, mod_expr_value *e)
{
    std::cout << "visit expr value\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

static mod_node *visit_unit(const visitor *v, deduce_ctx *dt_ctx, mod_unit *e)
{
    std::cout << "visit unit\n";
    visit_children(v, dt_ctx, e);
    return nullptr;
}

bool deduce_types(context *ctx, mod_node *node)
{
    visitor v(ctx);
    v.visit[MOD_FUNCTION] = (visit_fn) visit_function;
    v.visit[MOD_VARIABLE] = (visit_fn) visit_variable;
    v.visit[MOD_OBJECT] = (visit_fn) visit_object;
    v.visit[MOD_STRUCT] = (visit_fn) visit_struct;
    v.visit[MOD_TYPE] = (visit_fn) visit_type;
    v.visit[MOD_BODY] = (visit_fn) visit_body;
    v.visit[MOD_STMT_RETURN] = (visit_fn) visit_stmt_return;
    v.visit[MOD_EXPR_APPLY] = (visit_fn) visit_expr_apply;
    v.visit[MOD_EXPR_VALUE] = (visit_fn) visit_expr_value;
    v.visit[MOD_UNIT] = (visit_fn) visit_unit;

    deduce_ctx dt_ctx;

    visit(&v, &dt_ctx, node);
    return true;
}

} // owl
