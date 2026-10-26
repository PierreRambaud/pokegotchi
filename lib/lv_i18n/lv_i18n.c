#include "./lv_i18n.h"


////////////////////////////////////////////////////////////////////////////////
// Define plural operands
// http://unicode.org/reports/tr35/tr35-numbers.html#Operands

// Integer version, simplified

#define UNUSED(x) (void)(x)

static inline uint32_t op_n(int32_t val) { return (uint32_t)(val < 0 ? -val : val); }
static inline uint32_t op_i(uint32_t val) { return val; }
// always zero, when decimal part not exists.
static inline uint32_t op_v(uint32_t val) { UNUSED(val); return 0;}
static inline uint32_t op_w(uint32_t val) { UNUSED(val); return 0; }
static inline uint32_t op_f(uint32_t val) { UNUSED(val); return 0; }
static inline uint32_t op_t(uint32_t val) { UNUSED(val); return 0; }

static lv_i18n_phrase_t en_singulars[] = {
    {"actions.menu.bag", "Bag"},
    {"actions.menu.sleep", "Sleep"},
    {"actions.menu.heal", "Heal"},
    {"actions.menu.use", "Use"},
    {"actions.menu.wake_up", "Wake up"},
    {"bag.apple.description", "Beautiful fruit"},
    {"bag.apple.name", "Apple"},
    {"bag.beans.description", "English beans"},
    {"bag.beans.name", "Beans"},
    {"bag.berry.description", "A simple fruit"},
    {"bag.berry.name", "Berry"},
    {"bag.candy.description", "A box full of candies, not very healthy!"},
    {"bag.candy.name", "Candy box"},
    {"bag.cheese.description", "French cheese, the best one"},
    {"bag.cheese.name", "Cheese"},
    {"bag.chicken.description", "Fried Chicken"},
    {"bag.chicken.name", "Chicken"},
    {"bag.coconut_milk.description", "Always good with chicken"},
    {"bag.coconut_milk.name", "Coconut milk"},
    {"bag.frozen_carrots.description", "Come from the south"},
    {"bag.frozen_carrots.name", "Frozen carrot"},
    {"bag.haricots.description", "Green vegetable"},
    {"bag.haricots.name", "Haricots"},
    {"bag.honey.description", "Honey of acacia"},
    {"bag.honey.name", "Honey"},
    {"bag.milk.description", "Organic milk"},
    {"bag.milk.name", "Milk"},
    {"bag.noodles.description", "Fresh noodles!"},
    {"bag.noodles.name", "Noodles"},
    {"bag.spices.description", "Add some spice to your life"},
    {"bag.spices.name", "Spices"},
    {"bag.sugar_star.description", "A magic candy"},
    {"bag.sugar_star.name", "Sugar star"},
    {"bag.water.description", "Perfect water"},
    {"bag.water.name", "Water"},
    {"bar.hunger", "Hunger"},
    {"bar.life", "Life"},
    {"bar.mood", "Mood"},
    {"bar.sleepiness", "Sleepiness"},
    {"home.start", "New game"},
    {"menu.games", "Games"},
    {"menu.options", "Options"},
    {"menu.save", "Save"},
    {"game.level", "Level"},
    {"menu.train", "Train"},
    {"menu.play", "Play"},
    {"menu.options.title", "Options"},
    {"menu.options.brightness", "Brightness"},
    {"pokemon.pichu.description", "Despite its small size, it can zap even adult humans. However, if it does so, it also surprises itself."},
    {"pokemon.pikachu.description", "Pikachu can generate powerful electricity with its extra soft and super stretchy cheek pouches."},
    {"pokemon.raichu.description", "Its long tail serves as a ground to protect itself from its own high-voltage power."},
    {"pokemon.pichu.name", "Pichu"},
    {"pokemon.pikachu.name", "Pikachu"},
    {"pokemon.raichu.name", "Raichu"},
    {"home.load", "Load game"},
    {"sd.card.not_found", "SD card not found"},
    {"game.load.error", "Unable to load save file"},
    {"game.load.unserialize.error", "Unable to unserialize data from the file"},
    {"game.save.failed", "Error while saving"},
    {"game.save.success", "Game saved!"},
    {"pokemon.eevee.description", "It has the ability to alter the composition of its body to suit its surrounding environment."},
    {"pokemon.vaporeon.description", "When Vaporeon’s fins begin to vibrate, it is a sign that rain will come within a few hours."},
    {"pokemon.jolteon.description", "If it is angered or startled, the fur all over its body bristles like sharp needles that pierce foes."},
    {"pokemon.flareon.description", "Once it has stored up enough heat, this Pokémon’s body temperature can reach up to 1,700 degrees Fahrenheit."},
    {"pokemon.eevee.name", "Eevee"},
    {"pokemon.vaporeon.name", "Vaporeon"},
    {"pokemon.jolteon.name", "Jolteon"},
    {"pokemon.flareon.name", "Flareon"},
    {"home.start.choice", "Choose wisely"},
    {"actions.menu.clean", "Clean"},
    {"game.draw.color", "Color"},
    {"game.draw.size", "Size %d"},
    {"game.draw.clear", "Clear"},
    {"game.bird.start", "Press Button B to start"},
    {"game.bird.highscore", "HIGHSCORE"},
    {"game.bird.gameover", "GAME OVER"},
    {"game.bird.score", "Score:"},
    {"game.bird.restart", "Press Button B"},
    {"game.bird.maxscore", "Max Score:"},
    {"game.save.create.button", "Create"},
    {"game.save.replace.button", "Replace"},
    {"game.save.file.invalid", "Invalid file name"},
    {"game.error", "Error"},
    {"menu.game.draw", "Drawing"},
    {"menu.game.bird", "Floppy Bird"},
    {"ball.poke", "Poké Ball"},
    {"ball.super", "Super Ball"},
    {"ball.hyper", "Hyper Ball"},
    {"ball.master", "Master Ball"},
    {"ball.love", "Love ball"},
    {"ball.fast", "Fast ball"},
    {"ball.memory", "Memory Ball"},
    {"ball.moon", "Moon Ball"},
    {"ball.dream", "Dream Ball"},
    {"menu.options.ball", "Ball choice"},
    {"pokemon.ko.title", "Pokémon K.O."},
    {"pokemon.ko.message", "Game Over!"},
    {"game.save.box.delete", "Delete"},
    {"game.save.box.choose", "What to do?"},
    {"game.save.box.replace", "Replace"},
    {"menu.game.sky", "Sky Race"},
    {"game.sky.choose", "Choose your Pokemon"},
    {"game.sky.articuno", "Articuno"},
    {"game.sky.latios", "Latios"},
    {"game.sky.latias", "Latias"},
    {"game.sky.calibrate", "Hold steady..."},
    {"game.sky.help", "Tilt to fly through the rings"},
    {"game.sky.score", "Score: %d"},
    {"game.sky.best", "Best: %d"},
    {"game.sky.newbest", "NEW RECORD!"},
    {"game.sky.gameover", "GAME OVER"},
    {"game.sky.retry", "B: again  A: change  C: back"},
    {"game.sky.invert.on", "Up/down inverted (tap to change)"},
    {"game.sky.invert.off", "Up/down normal (tap to change)"},
    {"game.minigame.back", "C: back to your Pokemon"},
    {"game.draw.clear_back", "Clear (hold: back)"},
    {"game.sky.back", "Hold B: back to your Pokemon"},
    {"pokemon.espeon.name", "Espeon"},
    {"pokemon.umbreon.name", "Umbreon"},
    {"pokemon.leafeon.name", "Leafeon"},
    {"pokemon.glaceon.name", "Glaceon"},
    {"pokemon.espeon.description", "It is extremely loyal to a trainer it considers worthy. Its fine fur can sense the slightest change in the air."},
    {"pokemon.umbreon.description", "When darkness falls, the rings on its body begin to glow, striking fear in the hearts of anyone nearby."},
    {"pokemon.leafeon.description", "Just like a plant, it uses photosynthesis. As a result, it is always enveloped in clear air."},
    {"pokemon.glaceon.description", "It lowers its body heat to freeze its fur. The hairs then become like needles it can fire."},
    {"pokemon.egg.name", "Egg"},
    {"pokemon.egg.description", "Something lives inside. Sometimes it moves... Take it for a walk: it will hatch after 500 steps, or 5 minutes."},
    {"pokemon.stats", "Level %d - XP %d/%d - Age: %lu day(s)\n%s\nCare mistakes: %d - %s\nSteps: %lu today - %lu in total"},
    {"pokemon.friendship.1", "It doesn't trust you yet."},
    {"pokemon.friendship.2", "It's getting used to you."},
    {"pokemon.friendship.3", "It likes you."},
    {"pokemon.friendship.4", "It is very friendly toward you!"},
    {"pokemon.friendship.5", "It adores you, it could not be happier!"},
    {"pokemon.status.sick", "Sick"},
    {"pokemon.status.healthy", "Healthy"},
    {"bag.stone.thunder", "Thunder Stone"},
    {"bag.stone.water", "Water Stone"},
    {"bag.stone.fire", "Fire Stone"},
    {"bag.stone.leaf", "Leaf Stone"},
    {"bag.stone.ice", "Ice Stone"},
    {"game.hatch.title", "Oh?"},
    {"game.hatch.message", "The egg hatched! It is %s!"},
    {"game.evolve.title", "Congratulations!"},
    {"game.evolve.message", "Your %s evolved into %s!"},
    {"game.reward.title", "Welcome back!"},
    {"game.reward.stone", "%s found a %s!"},
    {"game.reward.fun", "%s had a lot of fun!"},
    {"game.stone.no_effect", "It won't have any effect."},
    {"menu.options.clock", "Clock"},
    {"menu.options.clock.set", "Set"},
    {"menu.options.clock.done", "Clock updated!"},
    {"game.egg.steps", "%d / %d steps"},
    {"game.steps.today", "Today: %lu steps"},
    {"menu.options.speed", "Speed of the days"},
    {"menu.options.speed.fast", "Fast (1 day = 10 minutes)"},
    {"menu.options.speed.normal", "Normal (1 day = 1 hour)"},
    {"menu.options.speed.real", "Real (1 day = 24 hours)"},
    {"menu.options.sound", "Sound effects"},
    {"home.speed.title", "How fast do the days go by?"},
    {"menu.options.speed.slow", "Slow (1 day = 4 hours)"},
    {NULL, NULL} // End mark
};



static uint8_t en_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);
    uint32_t i = op_i(n); UNUSED(i);
    uint32_t v = op_v(n); UNUSED(v);

    if ((i == 1 && v == 0)) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t en_lang = {
    .locale_name = "en",
    .singulars = en_singulars,

    .locale_plural_fn = en_plural_fn
};

static lv_i18n_phrase_t fr_singulars[] = {
    {"actions.menu.bag", "Sac"},
    {"actions.menu.sleep", "Dormir"},
    {"actions.menu.heal", "Soigner"},
    {"actions.menu.use", "Utiliser"},
    {"actions.menu.wake_up", "Se réveiller"},
    {"bag.apple.description", "Quelle belle pomme"},
    {"bag.apple.name", "Pomme"},
    {"bag.beans.description", "De bons haricots"},
    {"bag.beans.name", "Haricots"},
    {"bag.berry.description", "Une simple baie"},
    {"bag.berry.name", "Baie"},
    {"bag.candy.description", "Une boîte pleine, pas très bonne pour la santé!"},
    {"bag.candy.name", "Boîte de bonbons"},
    {"bag.cheese.description", "Fermier, comme on les aime"},
    {"bag.cheese.name", "Fromage"},
    {"bag.chicken.description", "Poulet frit"},
    {"bag.chicken.name", "Poulet"},
    {"bag.coconut_milk.description", "Très bon avec le poulet"},
    {"bag.coconut_milk.name", "Lait de coco"},
    {"bag.frozen_carrots.description", "Carotte du sud"},
    {"bag.frozen_carrots.name", "Carotte gelée"},
    {"bag.haricots.description", "Des légumes verts"},
    {"bag.haricots.name", "Haricots verts"},
    {"bag.honey.description", "Miel d'acacia"},
    {"bag.honey.name", "Miel"},
    {"bag.milk.description", "Lait BIO"},
    {"bag.milk.name", "Lait"},
    {"bag.noodles.description", "Nouilles fraîches!"},
    {"bag.noodles.name", "Nouilles"},
    {"bag.spices.description", "Pour mettre du piment dans ta vie"},
    {"bag.spices.name", "Épices"},
    {"bag.sugar_star.description", "Un bonbon magique"},
    {"bag.sugar_star.name", "Étoile sucrée"},
    {"bag.water.description", "Eau de source"},
    {"bag.water.name", "Eau"},
    {"bar.hunger", "Faim"},
    {"bar.life", "Vie"},
    {"bar.mood", "Humeur"},
    {"bar.sleepiness", "Sommeil"},
    {"home.start", "Nouvelle partie"},
    {"menu.games", "Jeux"},
    {"menu.options", "Options"},
    {"menu.save", "Sauvegarder"},
    {"game.level", "Niveau"},
    {"menu.train", "Entraînement"},
    {"menu.play", "Jouer"},
    {"menu.options.title", "Options"},
    {"menu.options.brightness", "Luminosité"},
    {"pokemon.pichu.description", "Malgré sa petite taille, il peut électrocuter de grandes personnes, ce qui le surprend également."},
    {"pokemon.pikachu.description", "Plus la puissance électrique de Pikachu est élevée, plus les poches de ses joues sont extensibles."},
    {"pokemon.raichu.description", "Sa longue queue agit comme une prise de terre qui l'empêche d'être affecté par le courant à haute tension accumulé dans son corps."},
    {"pokemon.pichu.name", "Pichu"},
    {"pokemon.pikachu.name", "Pikachu"},
    {"pokemon.raichu.name", "Raichu"},
    {"home.load", "Charger une partie"},
    {"sd.card.not_found", "Carte SD introuvable"},
    {"game.load.error", "Erreur lors du chargement du fichier"},
    {"game.load.unserialize.error", "Problème lors de la récupération des données"},
    {"game.save.failed", "Impossible de sauvegarder"},
    {"game.save.success", "Sauvegarde effectuée"},
    {"pokemon.eevee.description", "Il a la capacité de changer la composition de son corps pour s'adapter à son environnement."},
    {"pokemon.vaporeon.description", "Quand ses nageoires se mettent à vibrer, c'est le signe qu'il va pleuvoir dans les heures qui suivent."},
    {"pokemon.jolteon.description", "S'il est irrité ou surpris, toute la fourrure de son corps se dresse comme des aiguilles pour percer ses ennemis."},
    {"pokemon.flareon.description", "Après avoir emmagasiné suffisamment de chaleur, sa température corporelle peut monter jusqu'à 900 °C."},
    {"pokemon.eevee.name", "Evoli"},
    {"pokemon.vaporeon.name", "Aquali"},
    {"pokemon.jolteon.name", "Voltali"},
    {"pokemon.flareon.name", "Pyroli"},
    {"home.start.choice", "Choisissez judicieusement"},
    {"actions.menu.clean", "Nettoyer"},
    {"game.draw.color", "Couleur"},
    {"game.draw.size", "Taille %d"},
    {"game.draw.clear", "Effacer"},
    {"game.bird.start", "Appuyer sur le bouton B"},
    {"game.bird.highscore", "MEILLEUR SCORE"},
    {"game.bird.gameover", "FIN DE PARTIE"},
    {"game.bird.score", "Score:"},
    {"game.bird.restart", "Appuyer sur le bouton B"},
    {"game.bird.maxscore", "Score max:"},
    {"game.save.create.button", "Créer"},
    {"game.save.replace.button", "Remplacer"},
    {"game.save.file.invalid", "Nom de fichier invalide"},
    {"game.error", "Erreur"},
    {"menu.game.draw", "Dessin"},
    {"menu.game.bird", "Floppy Bird"},
    {"ball.poke", "Poké Ball"},
    {"ball.super", "Super Ball"},
    {"ball.hyper", "Hyper Ball"},
    {"ball.master", "Master Ball"},
    {"ball.love", "Love ball"},
    {"ball.fast", "Rapide ball"},
    {"ball.memory", "Mémoire Ball"},
    {"ball.moon", "Lune Ball"},
    {"ball.dream", "Rêve Ball"},
    {"menu.options.ball", "Choix de la Ball"},
    {"pokemon.ko.title", "Pokémon K.O"},
    {"pokemon.ko.message", "La partie est terminée !"},
    {"game.save.box.delete", "Supprimer"},
    {"game.save.box.choose", "Que faire ?"},
    {"game.save.box.replace", "Remplacer"},
    {"menu.game.sky", "Sky Race"},
    {"game.sky.choose", "Choisis ton Pokemon"},
    {"game.sky.articuno", "Artikodin"},
    {"game.sky.latios", "Latios"},
    {"game.sky.latias", "Latias"},
    {"game.sky.calibrate", "Ne bouge plus..."},
    {"game.sky.help", "Incline pour passer dans les anneaux"},
    {"game.sky.score", "Score : %d"},
    {"game.sky.best", "Record : %d"},
    {"game.sky.newbest", "NOUVEAU RECORD !"},
    {"game.sky.gameover", "FIN DE PARTIE"},
    {"game.sky.retry", "B : rejouer  A : changer  C : retour"},
    {"game.sky.invert.on", "Haut/bas inverses (toucher pour changer)"},
    {"game.sky.invert.off", "Haut/bas normal (toucher pour changer)"},
    {"game.minigame.back", "C : retour au Pokemon"},
    {"game.draw.clear_back", "Effacer (maintenir : retour)"},
    {"game.sky.back", "Maintenir B : retour au Pokemon"},
    {"pokemon.espeon.name", "Mentali"},
    {"pokemon.umbreon.name", "Noctali"},
    {"pokemon.leafeon.name", "Phyllali"},
    {"pokemon.glaceon.name", "Givrali"},
    {"pokemon.espeon.description", "Il est d'une loyauté absolue envers le Dresseur qu'il juge digne. Sa fourrure perçoit le moindre changement dans l'air."},
    {"pokemon.umbreon.description", "À la nuit tombée, les anneaux de son corps se mettent à briller et terrifient tous ceux qui l'approchent."},
    {"pokemon.leafeon.description", "Comme une plante, il pratique la photosynthèse. L'air qui l'entoure est donc toujours pur."},
    {"pokemon.glaceon.description", "Il abaisse sa température pour geler son pelage, dont les poils deviennent des aiguilles qu’il peut lancer."},
    {"pokemon.egg.name", "Oeuf"},
    {"pokemon.egg.description", "Quelque chose vit à l'intérieur. Parfois, ça bouge... Emmène-le marcher : il éclora après 500 pas, ou 5 minutes."},
    {"pokemon.stats", "Niveau %d - XP %d/%d - Âge : %lu jour(s)\n%s\nErreurs de soin : %d - %s\nPas : %lu aujourd'hui - %lu au total"},
    {"pokemon.friendship.1", "Il ne te fait pas encore confiance."},
    {"pokemon.friendship.2", "Il commence à s'habituer à toi."},
    {"pokemon.friendship.3", "Il t'aime bien."},
    {"pokemon.friendship.4", "Il est très amical avec toi !"},
    {"pokemon.friendship.5", "Il t'adore, il ne pourrait pas être plus heureux !"},
    {"pokemon.status.sick", "Malade"},
    {"pokemon.status.healthy", "En forme"},
    {"bag.stone.thunder", "Pierre Foudre"},
    {"bag.stone.water", "Pierre Eau"},
    {"bag.stone.fire", "Pierre Feu"},
    {"bag.stone.leaf", "Pierre Plante"},
    {"bag.stone.ice", "Pierre Glace"},
    {"game.hatch.title", "Hein ?"},
    {"game.hatch.message", "L'œuf a éclos ! C'est %s !"},
    {"game.evolve.title", "Félicitations !"},
    {"game.evolve.message", "%s a évolué en %s !"},
    {"game.reward.title", "Bon retour !"},
    {"game.reward.stone", "%s a trouvé une %s !"},
    {"game.reward.fun", "%s s'est bien amusé !"},
    {"game.stone.no_effect", "Ça n'aura aucun effet."},
    {"menu.options.clock", "Horloge"},
    {"menu.options.clock.set", "OK"},
    {"menu.options.clock.done", "Horloge mise à jour !"},
    {"game.egg.steps", "%d / %d pas"},
    {"game.steps.today", "Aujourd'hui : %lu pas"},
    {"menu.options.speed", "Vitesse des journées"},
    {"menu.options.speed.fast", "Rapide (1 jour = 10 minutes)"},
    {"menu.options.speed.normal", "Normale (1 jour = 1 heure)"},
    {"menu.options.speed.real", "Réelle (1 jour = 24 heures)"},
    {"menu.options.sound", "Effets sonores"},
    {"home.speed.title", "À quelle vitesse passent les journées ?"},
    {"menu.options.speed.slow", "Lente (1 jour = 4 heures)"},
    {NULL, NULL} // End mark
};



static uint8_t fr_plural_fn(int32_t num)
{
    uint32_t n = op_n(num); UNUSED(n);
    uint32_t i = op_i(n); UNUSED(i);

    if ((((i == 0) || (i == 1)))) return LV_I18N_PLURAL_TYPE_ONE;
    return LV_I18N_PLURAL_TYPE_OTHER;
}

static const lv_i18n_lang_t fr_lang = {
    .locale_name = "fr",
    .singulars = fr_singulars,

    .locale_plural_fn = fr_plural_fn
};

const lv_i18n_language_pack_t lv_i18n_language_pack[] = {
    &en_lang,
    &fr_lang,
    NULL // End mark
};

////////////////////////////////////////////////////////////////////////////////


// Internal state
static const lv_i18n_language_pack_t * current_lang_pack;
static const lv_i18n_lang_t * current_lang;


/**
 * Reset internal state. For testing.
 */
void __lv_i18n_reset(void)
{
    current_lang_pack = NULL;
    current_lang = NULL;
}

/**
 * Set the languages for internationalization
 * @param langs pointer to the array of languages. (Last element has to be `NULL`)
 */
int lv_i18n_init(const lv_i18n_language_pack_t * langs)
{
    if(langs == NULL) return -1;
    if(langs[0] == NULL) return -1;

    current_lang_pack = langs;
    current_lang = langs[0];     /*Automatically select the first language*/
    return 0;
}

/**
 * Change the localization (language)
 * @param l_name name of the translation locale to use. E.g. "en-GB"
 */
int lv_i18n_set_locale(const char * l_name)
{
    if(current_lang_pack == NULL) return -1;

    uint16_t i;

    for(i = 0; current_lang_pack[i] != NULL; i++) {
        // Found -> finish
        if(strcmp(current_lang_pack[i]->locale_name, l_name) == 0) {
            current_lang = current_lang_pack[i];
            return 0;
        }
    }

    return -1;
}


static const char * __lv_i18n_get_text_core(lv_i18n_phrase_t * trans, const char * msg_id)
{
    uint16_t i;
    for(i = 0; trans[i].msg_id != NULL; i++) {
        if(strcmp(trans[i].msg_id, msg_id) == 0) {
            /*The msg_id has found. Check the translation*/
            if(trans[i].translation) return trans[i].translation;
        }
    }

    return NULL;
}


/**
 * Get the translation from a message ID
 * @param msg_id message ID
 * @return the translation of `msg_id` on the set local
 */
const char * lv_i18n_get_text(const char * msg_id)
{
    if(current_lang == NULL) return msg_id;

    const lv_i18n_lang_t * lang = current_lang;
    const void * txt;

    // Search in current locale
    if(lang->singulars != NULL) {
        txt = __lv_i18n_get_text_core(lang->singulars, msg_id);
        if (txt != NULL) return txt;
    }

    // Try to fallback
    if(lang == current_lang_pack[0]) return msg_id;
    lang = current_lang_pack[0];

    // Repeat search for default locale
    if(lang->singulars != NULL) {
        txt = __lv_i18n_get_text_core(lang->singulars, msg_id);
        if (txt != NULL) return txt;
    }

    return msg_id;
}

/**
 * Get the translation from a message ID and apply the language's plural rule to get correct form
 * @param msg_id message ID
 * @param num an integer to select the correct plural form
 * @return the translation of `msg_id` on the set local
 */
const char * lv_i18n_get_text_plural(const char * msg_id, int32_t num)
{
    if(current_lang == NULL) return msg_id;

    const lv_i18n_lang_t * lang = current_lang;
    const void * txt;
    lv_i18n_plural_type_t ptype;

    // Search in current locale
    if(lang->locale_plural_fn != NULL) {
        ptype = lang->locale_plural_fn(num);

        if(lang->plurals[ptype] != NULL) {
            txt = __lv_i18n_get_text_core(lang->plurals[ptype], msg_id);
            if (txt != NULL) return txt;
        }
    }

    // Try to fallback
    if(lang == current_lang_pack[0]) return msg_id;
    lang = current_lang_pack[0];

    // Repeat search for default locale
    if(lang->locale_plural_fn != NULL) {
        ptype = lang->locale_plural_fn(num);

        if(lang->plurals[ptype] != NULL) {
            txt = __lv_i18n_get_text_core(lang->plurals[ptype], msg_id);
            if (txt != NULL) return txt;
        }
    }

    return msg_id;
}

/**
 * Get the name of the currently used locale.
 * @return name of the currently used locale. E.g. "en-GB"
 */
const char * lv_i18n_get_current_locale(void)
{
    if(!current_lang) return NULL;
    return current_lang->locale_name;
}
