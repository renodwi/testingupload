#define MAX_ITEM 1000
#define MAX_ITEM_NAME 56
#define MAX_ITEM_DESCRIPTION 256

enum // ITEM CATEGORY
{
    ITEM_CATEGORY_DRINK,
    ITEM_CATEGORY_FOOD,
    ITEM_CATEGORY_TOOLS,
}

new itemCategoryName[][] = {
    "Drink", "Food", "Tools"
};

enum // ITEM TYPE
{
    ITEM_TYPE_WATER,
    ITEM_TYPE_ALCOHOL,
    ITEM_TYPE_ORANGEJUICE,
    ITEM_TYPE_APPLEJUICE,
    ITEM_TYPE_COKE,

    ITEM_TYPE_PIZZA,
    ITEM_TYPE_BURGER,
    ITEM_TYPE_SNACK,

    ITEM_TYPE_FISHINGPOLE,
    ITEM_TYPE_WRENCH,
    ITEM_TYPE_CHAINSAW,
    ITEM_TYPE_CROWBAR
}

enum ITEM_INFO
{
    itemCategory,
    itemType,
    itemModel,
    itemMaxStack,
    itemIntValue,
    Float:itemFloatValue,
    itemName[MAX_ITEM_NAME],
    itemUnitName[MAX_ITEM_NAME],
    itemDescription[MAX_ITEM_DESCRIPTION],
}
new itemInfo[MAX_ITEM][ITEM_INFO],
    Iterator:Items<MAX_ITEM>;

