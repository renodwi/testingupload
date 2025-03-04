stock CreateItem(const name[], const unitname[], const desc[], category, type, model, max_stack, int_value, Float:float_value)
{
    new itemid = Iter_Free(Items);

    itemInfo[itemid][itemCategory] = category;
    itemInfo[itemid][itemType] = type;
    itemInfo[itemid][itemModel] = model;
    itemInfo[itemid][itemMaxStack] = max_stack;
    itemInfo[itemid][itemIntValue] = int_value;
    itemInfo[itemid][itemFloatValue] = float_value;
    format(itemInfo[itemid][itemName], MAX_ITEM_NAME + 1, name);
    format(itemInfo[itemid][itemUnitName], MAX_ITEM_NAME + 1, unitname);
    format(itemInfo[itemid][itemDescription], MAX_ITEM_DESCRIPTION + 1, desc);

    Iter_Add(Items, itemid);
    return itemid;
}

stock GetItemCategory(itemid) 
{
    new value = itemInfo[itemid][itemCategory];
    return value;
}

stock GetItemType(itemid) 
{
    new value = itemInfo[itemid][itemType];
    return value;
}

stock GetItemModel(itemid) 
{
    new value = itemInfo[itemid][itemModel];
    return value;
}

stock GetItemName(itemid) 
{
    new value[MAX_ITEM_NAME + 1];
    format(value, sizeof(value), itemInfo[itemid][itemName]);
    return value;
}

stock GetItemDescription(itemid) 
{
    new value[MAX_ITEM_DESCRIPTION + 1];
    format(value, sizeof(value), itemInfo[itemid][itemDescription]);
    return value;
}

stock GetItemCategoryName(category) 
{
    new name[50];
    format(name, sizeof(name), "%s", itemCategoryName[category]);
    return name;
}

stock GetItemIDByType(type) 
{
    new itemid = -1;
    foreach(new i : Items) 
    {
        if(Iter_Contains(Items, i) && itemInfo[i][itemType] == type) 
        {
            itemid = i;
            break;
        }
    }
    return itemid;
}

stock GetItemUnitName(type) 
{
    new unitname[MAX_ITEM_NAME];
    format(unitname, sizeof(unitname), "%s", itemInfo[GetItemIDByType(type)][itemUnitName]);
    return unitname;
}

stock GetItemMaxStack(type)
{
    new maxstack;
    maxstack = itemInfo[GetItemIDByType(type)][itemMaxStack];
    return maxstack;
}