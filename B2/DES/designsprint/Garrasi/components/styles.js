import { StyleSheet } from 'react-native'

const back = StyleSheet.create({
    inscription_container: {
        flex: 1,
        backgroundColor: '#D6C9C9',
        justifyContent: 'center',
    },
    container: {
        flex: 1,
        backgroundColor: '#E8EEF2',
        alignItems: 'center',
        justifyContent: 'center',
    },
})

const texts = StyleSheet.create({
    title_of_page: {
        fontFamily: 'Onyx',
        fontSize: 80,
        fontStyle: 'normal',
        color: '#5A5A5A'
    },
    inscription: {
        fontFamily: 'Onyx',
        fontSize: 120,
        fontStyle: 'normal',
        alignSelf: 'center',
        color: '#5A5A5A',
    },
    enter_text: {
        fontFamily: 'lucida-sans-italic',
        fontSize: 14,
        alignItems: 'center',
        alignSelf: 'center',
        color: '#5A5A5A',
        width: 350,
        height: 50,
        backgroundColor: '#E8EEF2',
        borderRadius: 15,
        marginBottom: 10,
        paddingLeft: 10,
    },
    forgot_password: {
        fontFamily: 'lucida-sans-italic',
        fontSize: 14,
        color: 'grey',
    },
    connexion: {
        paddingTop: 17,
        alignSelf: 'center',
        justifyContent: 'center',
        fontFamily: 'lucida-sans-normal',
        fontSize: 19,
        color: '#E8EEF2',
    },
    pas_inscrit: {
        paddingTop: 12,
        alignSelf: 'center',
        fontFamily: 'lucida-sans-normal',
        fontSize: 21,
        color: '#5A5A5A',
    },
    pseudo_for_posts: {
        fontFamily: 'lucida-sans-normal',
        fontSize: 14,
        color: '#5A5A5A',
    },
    pseudo: {
        fontFamily: 'Onyx',
        fontSize: 50,
        fontStyle: 'normal',
        color: '#5A5A5A'
    },
    profil_text: {
        fontSize: 18,
        color: '#4A525A',
        textAlign: "center",
        justifyContent: 'center',
    },
})

const buttons = StyleSheet.create({
    forgot_password: {
        alignSelf: 'flex-end',
        alignContent: 'center',
        marginRight: 35,
        paddingBottom: 25,
    },
    connexion: {
        alignSelf: 'center',
        width: 350,
        height: 50,
        backgroundColor: '#5A5A5A',
        borderRadius: 15,
    },
})

const views = StyleSheet.create({
    top_bar: {
        flex: 3,
        backgroundColor: "#D6C9C9",
        flexDirection: 'row',
    },
    container: {
        flex: 15,
        backgroundColor: "#E8EEF2",
        padding: 10,
    },
    profil_container: {
        flex: 15,
        backgroundColor: '#E8EEF2',
    },
    bottom_bar: {
        flex: 2,
        backgroundColor: "#D6C9C9",
        flexDirection: 'row',
    },
})

const home = StyleSheet.create({
    bar_rechercher: {
        fontFamily: 'lucida-sans-normal',
        fontSize: 14,
        alignItems: 'center',
        alignSelf: 'center',
        color: '#5A5A5A',
        width: 390,
        height: 50,
        backgroundColor: '#FFFFFF',
        borderColor: '#5A5A5A',
        borderWidth: 1,
        borderRadius: 15,
        paddingLeft: 10,
        paddingRight: 10,
        marginBottom: 10,
    },
    view_rechercher: {
    }

})

const images = StyleSheet.create({
    profileImgContainer: {
        marginLeft: 8,
        height: 80,
        width: 80,
        borderRadius: 40,
    },
    profileImg: {
        height: 80,
        width: 80,
        borderRadius: 40,
    },
})

const add_post = StyleSheet.create({
    top_bar: {
        flex: 2,
        backgroundColor: "#D6C9C9",
        flexDirection: 'row',
    },
    container: {
        flex: 15,
        backgroundColor: "#E8EEF2",
        padding: 10,
    },
    search_bar: {
        fontFamily: 'lucida-sans-normal',
        fontSize: 14,
        alignItems: 'center',
        alignSelf: 'center',
        color: '#5A5A5A',
        width: 390,
        height: 40,
        backgroundColor: '#FFFFFF',
        borderColor: '#5A5A5A',
        borderWidth: 1,
        borderRadius: 15,
        paddingLeft: 10,
        paddingRight: 10,
        marginBottom: 10,
    },
    description_bar: {
        fontFamily: 'lucida-sans-normal',
        fontSize: 14,
        alignItems: 'center',
        alignSelf: 'center',
        color: '#5A5A5A',
        width: 390,
        height: 100,
        backgroundColor: '#FFFFFF',
        borderColor: '#5A5A5A',
        borderWidth: 1,
        borderRadius: 15,
        paddingLeft: 10,
        paddingRight: 10,
        marginBottom: 10,
    },
    publish_opacity: {
        alignSelf: 'center',
        alignItems: 'center',
        justifyContent: 'center',
        width: 390,
        height: 50,
        borderRadius: 15,
        borderColor: 'black',
        borderWidth: 1,
    },
    publish_text: {
        fontFamily: 'lucida-sans-normal',
        fontSize: 19,
    },
})

const params = StyleSheet.create({
    title: {
        fontFamily: 'Onyx',
        fontSize: 60,
        fontStyle: 'normal',
        color: '#5A5A5A',
        paddingTop: 35,
    },
    buttons: {
        width: 380,
        height: 40,
        borderWidth: 1,
        borderColor: '#5A5A5A',
        backgroundColor: 'white',
        borderRadius: 25,
        justifyContent: 'center',
        marginBottom: 10,
    },
    text_in_buttons: {
        fontSize: 18,
        fontFamily: 'lucida-sans-normal',
        color: '#5A5A5A',
    },
    footer: {
        marginLeft: 20,
        marginRight: 20,
        marginTop: 20,
        fontSize: 18,
        fontFamily: 'lucida-sans-normal',
        color: '#5A5A5A',
        textAlign: 'center',
    },
    button_deconnect: {
        marginTop: 20,
        color: 'blue',
        fontSize: 18,
        fontFamily: 'lucida-sans-normal',
        marginBottom: 25,
    },
    button_supp: {
        color: 'red',
        fontSize: 18,
        fontFamily: 'lucida-sans-normal',
    },
})

export { back, texts, buttons, views, images, home, add_post, params }