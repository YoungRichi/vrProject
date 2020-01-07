Result = {result = "ok"}

str = ""


function Action()
 Result["result"] = str .. "+" .. str
end

function Init(context)
 str = context["item"]
end
